
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction();

  private:
    G4VPhysicalVolume* Construct();

    // G4VPhysicalVolume* physiCrystal;
    // void constructAperture(G4VPhysicalVolume*	physiWorld);

    // virtual void ConstructSDandField();
    // G4LogicalVolume* logicDetector;  // shadowed declaration only needed if using sensitive detector class
};

#endif
