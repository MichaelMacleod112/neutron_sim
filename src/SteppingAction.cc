/////////////////////////////////////////////////////////////////////////
//
//
//
// This class collects information at three different levels:
// 1 - Energy deposited in the sensitive volume (LaBr3 crystal)
// 2 - Number of photons absorbed by the photocathode (or just generated!)
// 3 - Time at which each photon is absorbed
//
// This information is passed to the Event Action Class via
// the eventAction pointer
//
/////////////////////////////////////////////////////////////////////////

// total dose deposited in material
// dose per second based on flux rate
// energy spectrum before and after
// dose depth chart?
// activation calculations...
// alpha/lithium counting?




#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4SteppingManager.hh"
#include "RunAction.hh"

#include <string>

#include "G4RunManager.hh"

#include "fstream"
#include "iomanip"

using namespace std;

SteppingAction::SteppingAction(EventAction* EvAct)
:eventAction(EvAct)
{ }

SteppingAction::~SteppingAction()
{ }

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
	const G4String currentPhysicalName
    = aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();

	const G4String particleName
	= aStep->GetTrack()->GetDefinition()->GetParticleName();


	// const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	// G4VPhysicalVolume *physVol = touchable->GetVolume();
	// G4int copyNo = physVol->GetCopyNo();

	if (currentPhysicalName == "Detector"){
		if (particleName == "neutron"){
			eventAction->fRunAction->fNeutronHits++;
			}
		else if (particleName == "alpha"){
			eventAction->fRunAction->fAlphaHits++;
			}
		else if(particleName == "Li7"){
			eventAction->fRunAction->fLithiumHits++;
			}
			else if(particleName == "gamma"){
			eventAction->fRunAction->fGammas++;
			}
		}

		// aStep->GetTrack()->SetTrackStatus(fStopAndKill);
		G4double EdepStep = aStep->GetTotalEnergyDeposit();
		if (EdepStep > 0.) eventAction->EdepInCrystal = eventAction->EdepInCrystal + EdepStep;
		if (particleName == "opticalphoton"){
			// eventAction->absTime = aStep -> GetPreStepPoint() -> GetGlobalTime();
			aStep->GetTrack()->SetTrackStatus(fStopAndKill);

		}
		// remove if spectra are desired
		// aStep->GetTrack()->SetTrackStatus(fStopAndKill);




	// }

	// // check if the photon is absorbed in the sensitive volume
	// if (currentPhysicalName == "Cathode"){
		// G4double EdepStep2 = aStep->GetTotalEnergyDeposit();

		// if (EdepStep2 > 0.) eventAction->EdepInCathode = eventAction->EdepInCathode + EdepStep2;

		// const G4String ProcessName =
		// aStep -> GetPostStepPoint() -> GetProcessDefinedStep() -> GetProcessName();
		// if (ProcessName == "OpAbsorption"){


			// eventAction->absTime = aStep -> GetPreStepPoint() -> GetGlobalTime();
		// }
	// }
}
