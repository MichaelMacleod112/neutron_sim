#include "EventAction.hh"
#include "Analysis.hh"
//#include "Randomize.hh" // do we really need this?
#include <iomanip>

#include "RunAction.hh"
#include "G4GeneralParticleSource.hh"

#include "PrimaryGeneratorAction.hh"
#include "G4RunManager.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4UnitsTable.hh"

#include "globals.hh"

//#include "iomanip"

using namespace std;
using namespace CLHEP;

EventAction::EventAction(RunAction* runAction)
:G4UserEventAction(), fRunAction(runAction)//, EdepInCrystal(0.), nAbsPhotons(0.), absTime(0.)
{

}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{
	EdepInCrystal = 0.;

	// gammaHit = 0;

}

void EventAction::EndOfEventAction(const G4Event* evt)
{
		// G4int eventID = 1 + evt->GetEventID();
		// G4cout<<"Event ID : "<<eventID<<G4endl<<"Gamma hit crystal : "<<gammaHit<<G4endl;
		// runCount->counter+=gammaHit;
		// fRunAction->AccumulateHits(gammaHit);

	  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	  // fill histograms
	  analysisManager->FillH1(0, EdepInCrystal);

		fRunAction->TotalEnergyDeposit+=EdepInCrystal;

	  analysisManager->FillNtupleDColumn(0, EdepInCrystal);

	  analysisManager->AddNtupleRow();


}
