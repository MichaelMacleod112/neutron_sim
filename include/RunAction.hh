
#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4Accumulable.hh"

#include <fstream>

using namespace std;

class G4Run;

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    ~RunAction();

  public:
    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);

  	G4double xmin;
  	G4double xmax;
  	G4int binsize;
  	G4int nbins;
    G4double nInCrystal;

    G4double fNeutronHits;
    G4double fAlphaHits;
    G4double fLithiumHits;
    G4double fGammas;

    G4double TotalEnergyDeposit;

  private:
    // G4Accumulable<G4double> fTotalHits;
};

#endif
