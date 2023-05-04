///////////////////////////////////////////////////////////////////
//
// Apr/2015  E. Nacher -> DetectorConstruction.cc
//
///////////////////////////////////////////////////////////////////

#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Polycone.hh"
#include "G4Trd.hh"

#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"

#include "G4NistManager.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"

using namespace CLHEP;

DetectorConstruction::DetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{ }




G4VPhysicalVolume* DetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();

	//----------------------------------------------------
	// Material definitions
	//----------------------------------------------------

	G4String name, symbol;             //a=mass of a mole;
	G4double a, z, density;            //z=mean number of protons;

	// G4int ncomponents, natoms;

	G4double pressure    = 3.e-18*pascal;
	G4double temperature = 2.73*kelvin;
	density     = 1.e-25*g/cm3;

	G4Material* Vacuum = new G4Material(name="Galactic", z=1., a=1.01*g/mole,
	density,kStateGas,temperature,pressure);


	//the atomic properties of these are looked up via spec sheets of manufacturer

	//
	// define simple Elements
	//

	// O
	// a = 15.999*g/mole;
	// G4Element* O  = new G4Element(name="Oxygen" ,symbol="O" , z= 8., a);

	// Si
	// a = 28.0855*g/mole;
	// G4Element* Si  = new G4Element(name="Silicon"  ,symbol="Si" , z= 14., a);


	// Tungsten
	// G4Material* Tungsten = G4NistManager::Instance()->FindOrBuildMaterial("G4_W");

	// Lead
	// G4Material* Lead = G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb");

	// aluminium
	// G4Material* Aluminium = G4NistManager::Instance()->FindOrBuildMaterial("G4_Al");


	// waste materials

	// G4Material* Concrete = G4NistManager::Instance()->FindOrBuildMaterial("G4_CONCRETE");

	// test material - polyethylene
	G4Material *polyethylene = nist->FindOrBuildMaterial("G4_POLYETHYLENE");

// below defined a bunch of materials for neutron absorption testing/activation testing, attenuation and so on

	//define SWX-210 30% borated polyethylene
	G4Material *boratedSilicone = new G4Material("Borated Silicone", 1.190*g/cm3, 7);
	boratedSilicone->AddElement(nist->FindOrBuildElement("C"), 60.2*perCent);//60.33 to make 100%
	boratedSilicone->AddElement(nist->FindOrBuildElement("B"), 30.4*perCent);
	boratedSilicone->AddElement(nist->FindOrBuildElement("H"), 8.70*perCent);
	boratedSilicone->AddElement(nist->FindOrBuildElement("O"), 0.18*perCent);
	boratedSilicone->AddElement(nist->FindOrBuildElement("Fe"), 0.18*perCent);
	boratedSilicone->AddElement(nist->FindOrBuildElement("N"), 0.17*perCent);
	boratedSilicone->AddElement(nist->FindOrBuildElement("Si"), 0.04*perCent);

	// define SWX-237Z30 High Temperature Boron-Silicone
	G4Material *HTBoronSilicone = new G4Material("HT Boron Silicone", 1.59*g/cm3, 10);
	// HTBoronSilicone->AddElement(nist->FindOrBuildElement("O"), 100.0*perCent); // debug test
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("O"), 23.39*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("Al"), 5.67*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("Si"), 17.57*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("C"), 19.08*perCent);//19.10 to make 100%
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("H"), 3.27*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("B"), 30.51*perCent);//30.53 to make 100%
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("Na"), 0.04*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("Zn"), 0.10*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("Fe"), 0.18*perCent);
	HTBoronSilicone->AddElement(nist->FindOrBuildElement("N"), 0.17*perCent);

	G4double placeholder_density = 10.0;
	G4double density_tungsten = 19.3;
	G4double density_nickel = 8.9;
	G4double density_iron = 7.874;
	G4double density_copper = 8.96;

	// Tungsten 99.95% ( http://futurealloys.co.uk/tungsten-datasheet/ )
	G4Material *FA_tung = new G4Material("future alloys tungsten",19.3*g/cm3,7);
	FA_tung->AddElement(nist->FindOrBuildElement("W"),99.95*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("C"),0.01*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("O"),0.01*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("Ne"),0.01*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("Fe"),0.01*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("Ni"),0.01*perCent);
	FA_tung->AddElement(nist->FindOrBuildElement("Si"),0.01*perCent);

	// Tungsten (97%) / Nickel (2%) / Iron (1%)
	G4double mu = 0.97*density_tungsten + 0.02*density_nickel + 0.01*density_iron;
	G4Material *WNiFe = new G4Material("Tungsten-nickel-iron mix",mu*g/cm3,3);
	WNiFe->AddElement(nist->FindOrBuildElement("W"),97.0*perCent);
	WNiFe->AddElement(nist->FindOrBuildElement("Cu"),2.0*perCent);
	WNiFe->AddElement(nist->FindOrBuildElement("Cu"),1.0*perCent);

	// Tungsten 95% / Nickel (4%) / Copper (1%)
	mu = 0.95*density_tungsten + 0.04*density_nickel + 0.01*density_copper;
	G4Material *WNiCu = new G4Material("Tungsten-nickel-copper mix",mu*g/cm3,3);
	WNiCu->AddElement(nist->FindOrBuildElement("W"),95.0*perCent);
	WNiCu->AddElement(nist->FindOrBuildElement("Cu"),4.0*perCent);
	WNiCu->AddElement(nist->FindOrBuildElement("Cu"),1.0*perCent);

	// Tungsten (90%) / Copper (10%)
	mu = 0.9*density_tungsten + 0.1*density_copper;
	G4Material *WCu = new G4Material("Tungsten-copper mix",mu*g/cm3,2);
	WCu->AddElement(nist->FindOrBuildElement("W"),90.0*perCent);
	WCu->AddElement(nist->FindOrBuildElement("Cu"),10.0*perCent);

	//------------------------------------------------------
	// Detector geometry
	//------------------------------------------------------

	//
	// World
	//

	G4double WorldSize= 100.*cm;

	G4Box*
    solidWorld = new G4Box("World",		       	                  //its name
						   WorldSize/2,WorldSize/2,WorldSize/2);  //its size

	G4LogicalVolume*
    logicWorld = new G4LogicalVolume(solidWorld,      	//its solid
									 Vacuum,	        //its material
									 "World");		    //its name

	G4VPhysicalVolume*
    physiWorld = new G4PVPlacement(0,			    //no rotation
								   G4ThreeVector(),	//at (0,0,0)
									 "World",		    //its name
									 logicWorld,		//its logical volume
									 NULL,		    //its mother  volume
								   false,	       	//no boolean operation
								   0);			    //copy number


// detector volume
 	G4Box* solidDetector = new G4Box("Detector", 5.*cm,5.*cm,1.*cm);

 	G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector, Vacuum, "Detector");

 	G4VPhysicalVolume* physicalDetector = new G4PVPlacement(0,G4ThreeVector(0.,0.,2.*cm),"Detector",logicDetector, physiWorld,false,0);

	// shield

  G4Box* solidShield = new G4Box("Shield", 5.*cm,5.*cm,0.05*cm);

  G4LogicalVolume* logicShield = new G4LogicalVolume(solidShield, FA_tung, "Shield");
  G4VPhysicalVolume* physShield = new G4PVPlacement(0, G4ThreeVector(0.*cm,0.*cm,0.*cm), "Shield", logicShield, physiWorld, 0, 0);


	//------------------------------------------------------

	logicWorld->SetVisAttributes(G4VisAttributes::Invisible);

	//Blue color for boron shield
	G4VisAttributes* Att1= new G4VisAttributes(G4Colour(0.0,0.0,1.0));
	logicShield->SetVisAttributes(Att1);


	return physiWorld;
}

// void DetectorConstruction::ConstructSDandField(){
// 	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
//
// logicCrystal->SetSensitiveDetector(sensDet);
// }
