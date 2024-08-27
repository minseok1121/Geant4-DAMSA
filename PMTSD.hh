#ifndef PMTSD_h
#define PMTSD_h 1

#include "PMTHit.hh"

#include "G4VSensitiveDetector.hh"

#include <vector>

class G4DataVector;
class G4HCofThisEvent;
class G4Step;

class PMTSD : public G4VSensitiveDetector
{
 public:
  PMTSD(G4String name);
  ~PMTSD() override;

  void Initialize(G4HCofThisEvent*) override;
  G4bool ProcessHits(G4Step* aStep, G4TouchableHistory*) override;

  // A version of processHits active on boundary
  G4bool ProcessHits_boundary(const G4Step*, G4TouchableHistory*);

  // Initialize the arrays to store pmt positions
  inline void InitPMTs()
  {
    if(fPMTPositionsX)
      delete fPMTPositionsX;
    if(fPMTPositionsY)
      delete fPMTPositionsY;
    if(fPMTPositionsZ)
      delete fPMTPositionsZ;
    fPMTPositionsX = new G4DataVector();
    fPMTPositionsY = new G4DataVector();
    fPMTPositionsZ = new G4DataVector();
  }

  // Store a pmt position
  void SetPmtPositions(const std::vector<G4ThreeVector>& positions);

 private:
  PMTHitsCollection* fPMTHitCollection = nullptr;

  G4DataVector* fPMTPositionsX = nullptr;
  G4DataVector* fPMTPositionsY = nullptr;
  G4DataVector* fPMTPositionsZ = nullptr;

  G4int fHitCID = -1;
};

#endif
