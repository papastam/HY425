#ifndef __CPU_PRED_GAG_PREDICTOR_HH__
#define __CPU_PRED_GAG_PREDICTOR_HH__

#include <vector>

#include "base/sat_counter.hh"
#include "base/types.hh"
#include "cpu/pred/bpred_unit.hh"
#include "params/GAgPred.hh"

namespace gem5 {

namespace branch_prediction {

class GAgPred : public BPredUnit {
public:
  // this is basically the constructor of our class
  GAgPred(const GAgPredParams &params);

  // we will ignore it
  virtual void uncondBranch(ThreadID tid, Addr pc, void *&bp_history);

  // this function implements the main functionality of the predictor,
  // that is we will lookup the Global Predictor Table based on the index
  // we get from the Global History Register and we will return the found
  // prediction
  // Note that we inherit this pure virtual function from the main prediction
  // unit, thus we may or may not use these arguments
  bool lookup(ThreadID tid, Addr branch_addr, void *&bp_history);

  // we will ignore it
  void btbUpdate(ThreadID tid, Addr branch_addr, void *&bp_history);

  // this function implements the update logic of the predictor,
  // that is when we have the real result of a branch we have to update
  // the GPT first (using the same index, +taken -not_taken) and secondly
  // the GHR by shifting to the left AND 1taken 0not_taken
  void update(ThreadID tid, Addr branch_addr, bool taken, void *bp_history,
              bool squashed, const StaticInstPtr &inst, Addr corrTarget);

  void squash(ThreadID tid, void *bp_history) { assert(bp_history == NULL); }

private: //CP_CODE
  // the gHistory predictor register size
  unsigned historySize;

  // the width of the global predictor table
  unsigned gptWidth;

  // the height of the global predictor table
  unsigned gptHeight;

  /** Array of counters that make up the local predictor. */
  std::vector<SatCounter8> gpTable;

  /** The global history register. */
  unsigned long globalHistoryReg;

  /** The GHR mask */
  unsigned ghrMask;
};

} // namespace branch_prediction

} // namespace gem5

#endif
