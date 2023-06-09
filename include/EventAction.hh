
#ifndef EventAction_h
#define EventAction_h 1

#include <fstream>
// #include "GammaCounter.hh"

#include "G4UserEventAction.hh"
#include "globals.hh"

using namespace std;


class G4Event;
class RunAction;

class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction*);
    ~EventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event* );


    void accumulateEnergy(G4double);

    G4double  EdepInCrystal;

    RunAction*       fRunAction;
  private:
    // GammaCounter* runCount;

};

#endif
