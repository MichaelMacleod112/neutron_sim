/////////////////////////////////////////////////////////
//
// Apr/2015  E. Nacher -> PhysicsList.cc
//
// Physics List is a simplification of the LXePhysicsList
// ($G4INSTALL/examples/extended/optical/LXe). EM physics
// just registering G4EmStandardPhysics and no Decay Physics.
//
////////////////////////////////////////////////////////

#include "PhysicsList.hh"

#include "NeutronHPphysics.hh"

#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"

#include "G4ParticleTypes.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"


PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
	//add new units
  //
  new G4UnitDefinition( "millielectronVolt", "meV", "Energy", 1.e-3*eV);
  new G4UnitDefinition( "mm2/g",  "mm2/g", "Surface/Mass", mm2/g);
  new G4UnitDefinition( "um2/mg", "um2/mg","Surface/Mass", um*um/mg);

	// Neutron Physics
	RegisterPhysics(new NeutronHPphysics());


	RegisterPhysics (new G4DecayPhysics());
	RegisterPhysics (new G4RadioactiveDecayPhysics());
}


PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts(){

	SetCutsWithDefault();
}
