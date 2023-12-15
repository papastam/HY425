#include "cpu/pred/GAgPredictor.hh"

#include "base/intmath.hh"
#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/Fetch.hh"

namespace gem5 {

namespace branch_prediction {

// CP_CODE
GAgPred::GAgPred(const GAgPredParams &params)
    : BPredUnit(params),
      historySize(params.historySize),
      gptWidth(params.predSize),
      gptHeight(pow(2, historySize)),
      gpTable(gptHeight, SatCounter64(gptWidth)),
      globalHistoryReg(0),
      ghrMask(pow(2, historySize) - 1)
{
  if (gptWidth<=0) {
    fatal("Invalid global predictor size!\n");
  }

  if (historySize<=0 || historySize>32) {
    fatal("Invalid history size!\n");
  }

  // history register is a long long int, so it can only be 64 bits
  if(historySize > 64) {
    fatal("History size is too big!\n");
  }

  if(pow(2, historySize) != gptHeight) {
    fatal("history size and gtable Height doesnt match (%i != %i)!\n", pow(2, historySize), gptHeight);
  } 

  inform("history size: %i\n", historySize);

  inform("global predictor size: %i\n", gptWidth);

  inform("global predictor height: %i\n", gptHeight);

  inform("history mask: %#x\n", pow(2, historySize) - 1);

  inform("history size: %i\n", historySize);
}

// unused
void GAgPred::btbUpdate(ThreadID tid, Addr branch_addr, void *&bp_history) {
  // Place holder for a function that is called to update predictor history when
  // a BTB entry is invalid or not found.
}

// CP_CODE
bool GAgPred::lookup(ThreadID tid, Addr branch_addr, void *&bp_history) {
  // First we get the value of the index from the GHR
  // inform("Looking up index %#x\n", globalHistoryReg & ghrMask);

  unsigned history = globalHistoryReg & ghrMask;

  if (history >= gptHeight) {
    warn("Branch predictor table index is out of bounds!(%u)\n\n", history);
    return true;
  }

  // Then we get the value of the prediction from the GPT
  uint8_t prediction = gpTable[history];

  // Then we return the prediction
  return ((prediction << (gptWidth - 1)) >> (gptWidth - 1)) == 1;
}

// CP_CODE
void GAgPred::update(ThreadID tid, Addr branch_addr, bool taken,
                     void *bp_history, bool squashed, const StaticInstPtr &inst,
                     Addr corrTarget) {
  // inform("\n\n Update for branch: %s\n", taken? "taken" : "not taken");
  // inform("global history: %#x\n", globalHistoryReg & ghrMask);

  // Update the GPT (using the same index, +taken -not_taken)
  unsigned history = globalHistoryReg & ghrMask;

  if (history >= gptHeight) {
    warn("Branch predictor table index is out of bounds!(%u)\n\n", history);
    return;
  } 
  
  uint8_t prediction = gpTable[history];
  // uint8_t old_prediction = prediction;

  if (taken) {
    if (prediction < pow(gptWidth, 2) - 1) {
      prediction++;
    }
  } else {
    if (prediction > 0) {
      prediction--;
    }
  }

  // inform("prediction: %d->%d\n", old_prediction, prediction);

  // Then we update the GPT
  SatCounter64 new_prediction(prediction);
  gpTable[history] = new_prediction;
  
  // Update the GHR by shifting to the left AND 1taken 0not_taken
  globalHistoryReg = globalHistoryReg << 1;
  if (taken) {
    globalHistoryReg++;
  }
  
  // inform("new global history: %#x\n", globalHistoryReg & ghrMask);
}

// unused
void GAgPred::uncondBranch(ThreadID tid, Addr pc, void *&bp_history) {}

} // namespace branch_prediction

} // namespace gem5
