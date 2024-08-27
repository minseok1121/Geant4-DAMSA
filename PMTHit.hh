#ifndef PMTHit_h
#define PMTHit_h 1

#include "G4Allocator.hh"
#include "G4LogicalVolume.hh"
#include "G4THitsCollection.hh"
#include "G4VHit.hh"
#include "G4VPhysicalVolume.hh"

class PMTHit : public G4VHit
{
 public:
  PMTHit() = default;
  PMTHit(const PMTHit& right);
  ~PMTHit() override = default;

  const PMTHit& operator=(const PMTHit& right);
  G4bool operator==(const PMTHit& right) const;

  inline void* operator new(size_t);
  inline void operator delete(void* aHit);

  inline void SetPMTNumber(G4int n) { fPmtNumber = n; }
  inline G4int GetPMTNumber() { return fPmtNumber; }

  inline void SetPMTPhysVol(G4VPhysicalVolume* physVol)
  {
    fPhysVol = physVol;
  }
  inline G4VPhysicalVolume* GetPMTPhysVol() { return fPhysVol; }

  inline void SetPMTPos(G4double x, G4double y, G4double z)
  {
    fPos = G4ThreeVector(x, y, z);
  }

  inline G4ThreeVector GetPMTPos() { return fPos; }

 private:
  G4int fPmtNumber = -1;
  G4int fPhotons = 0;
  G4ThreeVector fPos;
  G4VPhysicalVolume* fPhysVol = nullptr;
};

typedef G4THitsCollection<PMTHit> PMTHitsCollection;

extern G4ThreadLocal G4Allocator<PMTHit>* PMTHitAllocator;

inline void* PMTHit::operator new(size_t)
{
  if(!PMTHitAllocator)
    PMTHitAllocator = new G4Allocator<PMTHit>;
  return (void*) PMTHitAllocator->MallocSingle();
}

inline void PMTHit::operator delete(void* aHit)
{
  PMTHitAllocator->FreeSingle((PMTHit*) aHit);
}

#endif
