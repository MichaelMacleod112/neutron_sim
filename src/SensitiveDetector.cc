// #include "SensitiveDetector.hh"
//
// MySensitiveDetector::MySensitiveDetector(G4String name ) : G4VSensitiveDetector(name)
// {}
//
// MySensitiveDetector::~MySensitiveDetector()
// {}
//
// G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
// {
//   G4Track *track = aStep->GetTrack();
//
//   G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
//
//   const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
//   G4VPhysicalVolume *physVol = touchable->GetVolume();
//   // G4int copyNo = physVol->GetCopyNo();
//
//   // G4ThreeVector posDetector = physVol->GetTranslation();
//   const G4String particleName
// 	= aStep->GetTrack()->GetDefinition()->GetParticleName();
//   if(particleName=="gamma")
//   {
//     G4int copyNo = physVol->GetCopyNo();
//     // G4cout<<"Detector hit with copy number : "<<copyNo<<G4endl;
//     aStep->GetTrack()->SetTrackStatus(fStopAndKill);
//   }
//   // aStep->eventAction->fRunAction->TotalHitCount++;
//
//
// // G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
// ;
// // G4AnalysisManager *man = G4AnalysisManager::Instance();
// // man->FillNtupleIColumn(0, copyNo);
// // man->FillNtupleDColumn(1, posDetector[0]);
// // man->FillNtupleDColumn(2, posDetector[1]);
// // // man->FillNtupleDColumn(3, posDetector[2]);
// // man->AddNtupleRow(0);
//
// return true;
//
// }
