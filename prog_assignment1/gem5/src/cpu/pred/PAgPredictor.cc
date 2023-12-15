#include "cpu/pred/PAgPredictor.hh"

#include "base/intmath.hh"
#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/Fetch.hh"

namespace gem5
{

namespace branch_prediction
{

PAgPred::PAgPred(const PAgPredParams &params)
    : BPredUnit(params),
      lhtableHeight(params.ltableHeight),
      lhtableWidth(params.lhistoryWidth),
      lhtable(lhtableHeight, 0),
      gptableHeight(params.gtableHeight),
      gptableWidth(params.gpredSize),
      gptable(gptableHeight, SatCounter64(gptableWidth)),
      lhMask(lhtableHeight - 1),
      gptableMask(gptableHeight - 1) 
{
    if (lhtableHeight<=0) {
        fatal("Invalid history size!\n");
    }

    if(lhtableWidth<=0 || lhtableWidth>32) {
        fatal("Invalid local history size!\n");
    }

    if (gptableWidth<=0) {
        fatal("Invalid global predictor size!\n");
    }

    if(gptableHeight<=0) {
        fatal("Invalid global history size!\n");
    }

    if(pow(2, lhtableWidth) != gptableHeight) {
        fatal("local history width and gtable Height doesnt match!\n");
    }

    // Set 0 on all local history registers
    for (int i = 0; i < lhtableHeight; i++) {
        lhtable[i] = 0;
    }

    inform("LH Table height: %i\n", lhtableHeight);

    inform("LH Table width: %i\n", lhtableWidth);

    inform("LH mask: %i\n", lhMask);

    inform("GP height: %i\n", gptableHeight);

    inform("GP width: %i\n", gptableWidth);
    
    inform("GP mask: %i\n", gptableMask);

    inform("instruction shift amount: %i\n", instShiftAmt);
}

// unused
void
PAgPred::btbUpdate(ThreadID tid, Addr branch_addr, void * &bp_history)
{
    
}

bool
PAgPred::lookup(ThreadID tid, Addr branch_addr, void * &bp_history)
{
    // this function implements the main functionality of the predictor,
    // that is we will lookup the Global Predictor Table based on the index
    // we get from the Global History Register and we will return the found
    // prediction
    // Note that we inherit this pure virtual function from the main prediction
    // unit, thus we may or may not use these arguments
    // First we calculate the index of the history table using the branch address
    // inform("\n\n Lookup for branch address: %d\n", (branch_addr >> instShiftAmt) & lhMask);

    unsigned gptable_index = lhtable[(branch_addr >> instShiftAmt) & lhMask];

    // inform("local history: %d\n", gptable_index);

    if (gptable_index >= gptable.size()) {
        warn("Branch predictor table index is out of bounds!(%u)\n\n", gptable_index);
        return false;
    }

    // Then we get the value of the prediction from the GPT
    uint8_t counter_val = gptable[gptable_index];

    // Then we return the prediction (LSB of the counter)
    return ((counter_val << (gptableWidth - 1)) >> (gptableWidth - 1)) == 1;
}

void
PAgPred::update(ThreadID tid, Addr branch_addr, bool taken, void *bp_history,
                bool squashed, const StaticInstPtr & inst, Addr corrTarget)
{
    // this function implements the update logic of the predictor,
    // that is when we have the real result of a branch we have to update
    // the GPT first (using the same index, +taken -not_taken) and secondly
    // the GHR by shifting to the left AND 1taken 0not_taken
    unsigned lhtable_index = (branch_addr >> instShiftAmt) & lhMask;
    // inform("\n\n Update for branch address: %d, branch was: %s\n", lhtable_index, taken? "taken" : "not taken");

    // First we calculate the index of the history table using the branch address
    unsigned local_history = lhtable[lhtable_index];

    // inform("old local history: %d\n", local_history);

    // Detect segfaults and print a warning message.
    if (local_history >= gptable.size()) {
        warn("Branch predictor table index is out of bounds!(%u)\n\n", local_history);
        return;
    }

    // Then we get the value of the prediction from the GPT
    uint8_t prediction_val = gptable[local_history];
    // uint8_t old_prediction_val = prediction_val;

    // Then we update the GPT (using the same index, +taken -not_taken)
    if (taken) {
        if (prediction_val < (gptableWidth - 1)) {
            prediction_val++;
        }
    } else {
        if (prediction_val > 0) {
            prediction_val--;
        }
    }

    // inform("global prediction: %d->%d\n", old_prediction_val,prediction_val);

    // Then we update the GPT
    SatCounter64 new_prediction_val(prediction_val);
    gptable[local_history] = new_prediction_val;

    // Then we update the GHR by shifting to the left AND 1taken 0not_taken
    lhtable[lhtable_index] = ((lhtable[lhtable_index] << 1) & gptableMask) | taken;
    // inform("new local history: %d\n", lhtable[lhtable_index]);
}

// unused
void
PAgPred::uncondBranch(ThreadID tid, Addr pc, void *&bp_history)
{
}

}

}
