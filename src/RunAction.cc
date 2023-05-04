///////////////////////////////////////////
//
// Oct/2015  Fabio -> RunAction.cc
//
///////////////////////////////////////////

#include "RunAction.hh"
#include "Analysis.hh"

#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AccumulableManager.hh"


#include "G4Run.hh"
#include "G4ios.hh"

#include <iomanip>

RunAction::RunAction() : G4UserRunAction(), fNeutronHits(0.), fAlphaHits(0.), fLithiumHits(0.)
{

	  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
	  G4cout << "Using " << analysisManager->GetType() << G4endl;

	  // Create directories
	  //analysisManager->SetHistoDirectoryName("histograms");
	  //analysisManager->SetNtupleDirectoryName("ntuple");
	  analysisManager->SetVerboseLevel(1);
	  analysisManager->SetFirstHistoId(0); // default is 0
	  analysisManager->SetFirstNtupleId(0); // default is 0

	  // Book histograms, ntuple
	  //

	  // Creating histograms



	  xmin = 1; // in keV
	  xmax = 1.5e3; // in keV
	  binsize = 2; // in keV
	  nbins= (int)((xmax-xmin)/binsize);
	  analysisManager->CreateH1("Histo1","Edep in Detector", nbins, xmin*keV, xmax*keV);


	  //
	  analysisManager->CreateNtuple("B4", "Edep and TrackL...");
	  analysisManager->CreateNtupleDColumn("Edep");

	  analysisManager->FinishNtuple();

}

RunAction::~RunAction()
{
	delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
		G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
		accumulableManager->Reset();

	  //inform the runManager to save random number seed
	  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);
		// nInDetector = 0;
	  // Get analysis manager
	  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	  // Open an output file
	  //
	  G4String fileName = "../data/test.root";
		// _0-5cmDepth_100k_1
	  analysisManager->OpenFile(fileName);



}

void RunAction::EndOfRunAction(const G4Run*)
{
		// write spectrum to root file
		G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
	  analysisManager->Write();
	  analysisManager->CloseFile();

		// print hits of neutrons and alphas
		G4cout<<"Total neutron hits : " << fNeutronHits << G4endl;
		G4cout<<"Total alpha hits : " << fAlphaHits << G4endl;
		G4cout<<"Total Li7 hits : " << fLithiumHits << G4endl;
		G4cout<<"Total gamma hits : " << fGammas << G4endl;

 // set neutron absorption etc and detector up properly to use this
		// G4cout<<"Total energy deposited : " << TotalEnergyDeposit << " MeV"<< G4endl;

}
