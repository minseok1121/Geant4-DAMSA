#include "PMTSD.hh"

#include "DetectorConstruction.hh"
#include "PMTHit.hh"
//#include "UserTrackInformation.hh"

#include "G4ios.hh"
#include "G4LogicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VTouchable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PMTSD::PMTSD(G4String name)
  : G4VSensitiveDetector(name)
{
  collectionName.insert("pmtHitCollection");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PMTSD::~PMTSD()
{
  delete fPMTPositionsX;
  delete fPMTPositionsY;
  delete fPMTPositionsZ;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PMTSD::SetPmtPositions(const std::vector<G4ThreeVector>& positions)
{
  for(size_t i = 0; i < positions.size(); ++i)
  {
    if(fPMTPositionsX)
      fPMTPositionsX->push_back(positions[i].x());
    if(fPMTPositionsY)
      fPMTPositionsY->push_back(positions[i].y());
    if(fPMTPositionsZ)
      fPMTPositionsZ->push_back(positions[i].z());
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PMTSD::Initialize(G4HCofThisEvent* hitsCE)
{
  fPMTHitCollection =
    new PMTHitsCollection(SensitiveDetectorName, collectionName[0]);

  if(fHitCID < 0)
  {
    fHitCID = G4SDManager::GetSDMpointer()->GetCollectionID(fPMTHitCollection);
  }
  hitsCE->AddHitsCollection(fHitCID, fPMTHitCollection);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool PMTSD::ProcessHits(G4Step*, G4TouchableHistory*) { return false; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Generates a hit and uses the postStepPoint's mother volume replica number
// PostStepPoint because the hit is generated manually when the photon is
// absorbed by the photocathode

G4bool PMTSD::ProcessHits_boundary(const G4Step* aStep, G4TouchableHistory*)
{
  // need to know if this is an optical photon
  if(aStep->GetTrack()->GetDefinition() !=
     G4OpticalPhoton::OpticalPhotonDefinition())
    return false;

  // User replica number 1 since photocathode is a daughter volume
  // to the pmt which was replicated
  G4int pmtNumber =
    aStep->GetPostStepPoint()->GetTouchable()->GetReplicaNumber();
  //G4cout << "pmtN : " << pmtNumber << G4endl;
  //G4cout << "pmtPos : " << (*fPMTPositionsX)[pmtNumber] << "     " << (*fPMTPositionsY)[pmtNumber] << "     " << (*fPMTPositionsZ)[pmtNumber] << G4endl;
  G4VPhysicalVolume* physVol =
    aStep->GetPostStepPoint()->GetTouchable()->GetVolume();
  //G4cout << "Postvolume: " << physVol->GetName() << G4endl;

  // Find the correct hit collection
  size_t n       = fPMTHitCollection->entries();
  PMTHit* hit = nullptr;
  for(size_t i = 0; i < n; i++)
  {
    if((*fPMTHitCollection)[i]->GetPMTNumber() == pmtNumber)
    {
      hit = (*fPMTHitCollection)[i];
      break;
    }
  }

  if(hit == nullptr)
  {                         // this pmt wasn't previously hit in this event
    hit = new PMTHit();  // so create new hit
    hit->SetPMTNumber(pmtNumber);
    hit->SetPMTPhysVol(physVol);
    fPMTHitCollection->insert(hit);
    hit->SetPMTPos((*fPMTPositionsX)[pmtNumber], (*fPMTPositionsY)[pmtNumber],
                   (*fPMTPositionsZ)[pmtNumber]);
  }

    G4double hitTime = aStep->GetPostStepPoint()->GetGlobalTime();
    G4double photonEnergy = aStep->GetPostStepPoint()->GetKineticEnergy();
    hit->AddPhotonInfo(hitTime, photonEnergy);
    
  hit->IncPhotonCount();


//G4cout << "PMTN : " << hit->GetPMTNumber() << G4endl;
//G4cout << "PMTPos : " << hit->GetPMTPos() << G4endl;
//G4cout << "PMTPhoton : " << hit->GetPhotonCount() << G4endl;
  return true;
}