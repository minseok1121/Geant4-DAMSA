#include "PMTHit.hh"

#include "G4Colour.hh"
#include "G4ios.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VVisManager.hh"

G4ThreadLocal G4Allocator<PMTHit>* PMTHitAllocator = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
PMTHit::PMTHit(const PMTHit& right)
  : G4VHit()
{
  fPmtNumber = right.fPmtNumber;
  fPhotons   = right.fPhotons;
  fPhysVol   = right.fPhysVol;
  //fDrawit    = right.fDrawit;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const PMTHit& PMTHit::operator=(const PMTHit& right)
{
  fPmtNumber = right.fPmtNumber;
  fPhotons   = right.fPhotons;
  fPhysVol   = right.fPhysVol;
  //fDrawit    = right.fDrawit;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool PMTHit::operator==(const PMTHit& right) const
{
  return (fPmtNumber == right.fPmtNumber);
}
*/