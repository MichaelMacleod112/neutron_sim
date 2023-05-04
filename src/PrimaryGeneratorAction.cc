///////////////////////////////////////////////////////////////////////////////////////
//
// Apr/2015  E. Nacher --> PrimaryGeneratorAction.cc
//
// Based on the /gps method. This simplifies life, but...
// The PrimaryGeneratorAction must be instantiated after initialization of the
// runManager in the main.cc:
//                          runManager->Initialize();
//                          runManager->SetUserAction(new PrimaryGeneratorAction);
//
///////////////////////////////////////////////////////////////////////////////////////

#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#include "G4ThreeVector.hh"
#include "globals.hh"

#include "G4ios.hh"
#include "fstream"
#include "iomanip"
#include "G4GeneralParticleSource.hh"


//GPS code
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	//
	// G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  // G4String particleName = "geantino";
  // G4ParticleDefinition *particle = particleTable->FindParticle("geantino");
	// Default values

	particleGun = new G4GeneralParticleSource();
	particleGun->SetCurrentSourceIntensity (1);
	particleGun->SetParticlePosition(G4ThreeVector());
	// particleGun->SetParticleEnergy(0.*GeV);
	// particleGun->SetParticleDefinition(particle);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // G4ParticleDefinition *particle = particleGun->GetParticleDefinition();
	// // create vertex
	// if(particle == G4Geantino::Geantino())
  // {
  //   G4int Z = 27;
  //   G4int A = 60;
  //   G4double charge = 0.*eplus;
  //   G4double energy = 0.*keV;
	//
  //   G4ParticleDefinition *ion = G4IonTable::GetIonTable()->GetIon(Z,A,energy);
	//
  //   particleGun->SetParticleDefinition(ion);
  //   particleGun->SetParticleCharge(charge);
  // }

	particleGun->GeneratePrimaryVertex(anEvent);
}
