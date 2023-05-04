#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

#include "G4ParticleGun.hh"
#include "G4IonTable.hh"
#include "G4Geantino.hh"

class G4GeneralParticleSource;
class G4Event;

// class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
// {
// public:
//   PrimaryGeneratorAction();
//   ~PrimaryGeneratorAction();
//
//   virtual void GeneratePrimaries(G4Event*);
//
// private:
//   G4ParticleGun *fParticleGun;
// };

// GPS code
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

public:
    virtual void GeneratePrimaries(G4Event* anEvent);

	// method to access particle gun
    G4GeneralParticleSource* GetParticleGun() const { return particleGun; }
private:
    G4GeneralParticleSource* particleGun;

};

#endif
