#include "globals.hh"

#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "SteppingActionDMG4.hh"

#include "DarkMatter.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4VVisManager.hh"
#include "G4UImanager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

#include "G4AutoLock.hh"

#include "G4SDManager.hh"
#include "PMTSD.hh"
#include "G4AnalysisManager.hh"

EventAction::EventAction(DetectorConstruction* myDC, DarkMatter* DMPointer)
    : G4UserEventAction(), myDetector(myDC), myDarkMatter(DMPointer), fEventCounter(0), NEmissions(0)
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    theSteppingAction->Reset();
    myDetector->SetAEmission(0);

    G4AutoLock lock(&eventMutex);
    theSteppingAction = dynamic_cast<SteppingActionDMG4*>(G4EventManager::GetEventManager()->GetUserSteppingAction());
    if (!theSteppingAction) {
        G4cerr << "Error: Casting G4UserSteppingAction to SteppingActionDMG4 failed!" << G4endl;
        return; // Handle the error accordingly
    }
    // Proceed with your logic using theSteppingAction
    fEventID = event->GetEventID();

    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    //G4cout << "reset? : " << fPMTCollID << "     " << fHitCount << G4endl;
    if(fPMTCollID < 0) fPMTCollID = SDman->GetCollectionID("pmtHitCollection");
    //G4cout << "PMTCollID : " << fPMTCollID << G4endl;
    fHitCount = 0;

}

void EventAction::EndOfEventAction(const G4Event* event)
{
    G4AutoLock lock(&eventMutex);
    fEventCounter++;
    if(fEventCounter % 100000 == 0){
    G4cout << "Processed " << fEventCounter << " events so far." << G4endl;
    }

    PMTHitsCollection* pmtHC = nullptr;
    G4HCofThisEvent* hitsCE  = event->GetHCofThisEvent();

    if(hitsCE) {
    if(fPMTCollID >= 0)
    {
      pmtHC = (PMTHitsCollection*) (hitsCE->GetHC(fPMTCollID));
    }
  }
auto analysisManager = G4AnalysisManager::Instance();
  if(pmtHC)
  {
    G4ThreeVector reconPos(0., 0., 0.);
    size_t pmts = pmtHC->entries();
    G4cout << "size? :     " << pmts << G4endl;
    // Gather info from all PMTs
    for(size_t i = 0; i < pmts; i++)
    {
      fHitCount += (*pmtHC)[i]->GetPhotonCount();
      reconPos += (*pmtHC)[i]->GetPMTPos() * (*pmtHC)[i]->GetPhotonCount();
      //G4cout << "hit : " << (*pmtHC)[i]->GetPhotonCount() << "  in  " << (*pmtHC)[i]->GetPMTPos() << G4endl;

      const std::vector<PhotonInfo>& photonInfos = (*pmtHC)[i]->GetPhotonInfos();
            for(const auto& info : photonInfos) {
                //G4cout << "(" << info.time/ns << " ns, " << info.energy/eV << " eV), ";
                G4double time = info.time;
                G4double energy = info.energy;
            analysisManager->FillH1(i, time);
            G4cout << "Histogram " << i << " entries: " << analysisManager->GetH1(i)->entries() << G4endl;
            }
            //G4cout << G4endl;
            //analysisManager->FillH1(i,1);
            
    }

    if(fHitCount > 0)
    {  // don't bother unless there were hits
      reconPos /= fHitCount;
    }
    G4cout << "reconPos: " << reconPos << G4endl;
    G4cout << "TotalN: " << fHitCount << G4endl;
    G4cout << G4endl;
    G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;
  }

}

