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

#include "RunAction.hh"
#include "G4AccumulableManager.hh"

EventAction::EventAction(DetectorConstruction* myDC, DarkMatter* DMPointer, RunAction* runAction)
    : G4UserEventAction(), myDetector(myDC), myDarkMatter(DMPointer), fEventCounter(0), NEmissions(0), fRunAction(runAction)
{
}

EventAction::~EventAction()
{
}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    theSteppingAction->Reset();
    myDetector->SetAEmission(0);
/*
    // Proceed with your logic using theSteppingAction
    fEventID = event->GetEventID();

    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    //G4cout << "reset? : " << fPMTCollID << "     " << fHitCount << G4endl;
    if(fPMTCollID < 0) fPMTCollID = SDman->GetCollectionID("pmtHitCollection");
    //G4cout << "PMTCollID : " << fPMTCollID << G4endl;
    fHitCount = 0;
*/
}

void EventAction::EndOfEventAction(const G4Event* event)
{
    G4AutoLock lock(&eventMutex);
    fEventCounter++;
    if(fEventCounter % 100000 == 0){
    G4cout << "Processed " << fEventCounter << " events so far." << G4endl;
    }
/*
    PMTHitsCollection* pmtHC = nullptr;
    G4HCofThisEvent* hitsCE  = event->GetHCofThisEvent();

    if(hitsCE) {
    if(fPMTCollID >= 0)
    {
      pmtHC = (PMTHitsCollection*) (hitsCE->GetHC(fPMTCollID));
    }
  }
//auto analysisManager = G4AnalysisManager::Instance();
 if (pmtHC)
{
    G4ThreeVector reconPos(0., 0., 0.);
    size_t pmts = pmtHC->entries();
    G4double TotE = 0;
    // Gather info from all PMTs
    for (size_t i = 0; i < pmts; i++)
    {
        fHitCount += (*pmtHC)[i]->GetPhotonCount();
        reconPos += (*pmtHC)[i]->GetPMTPos() * (*pmtHC)[i]->GetPhotonCount();

        G4ThreeVector pmtPos = (*pmtHC)[i]->GetPMTPos();
        int j = -1;
        if (pmtPos.z() == 261) j = 4;
        else if (pmtPos.z() == 371) j = 5;
        else if (pmtPos.z() == 481) j = 6;
        else if (pmtPos.z() == 591) j = 7;
        G4double posX = pmtPos.x() / cm;  // Convert position to cm if needed
        G4double posY = pmtPos.y() / cm;
        int binX = static_cast<int>(posX);
        int binY = static_cast<int>(posY);

        // Initialize time-energy map
        std::map<G4double, G4double> timeEnergyMap;
        const std::vector<PhotonInfo>& photonInfos = (*pmtHC)[i]->GetPhotonInfos();

        for (const auto& info : photonInfos)
        {
            G4double realtime = info.time;
            int time = static_cast<int>((realtime / 1000.0) * 10000);
            G4double energy = info.energy;
            // Accumulate energy for the histogram
            //fRunAction->GetEventDataH2()[j][binX][binY] += energy;

            // Accumulate energy by time
            if (timeEnergyMap.find(time) != timeEnergyMap.end())
            {
                timeEnergyMap[time] += energy;
            }
            else
            {
                timeEnergyMap[time] = energy;
            }
        }

        for (const auto& entry : timeEnergyMap)
        {
            G4double time = entry.first;
            G4double totalEnergy = entry.second;
            // Ensure that time does not exceed histogram limits (if applicable)
            if (time < 10000) // Assuming 10000 bins in the time histogram
            {
                //fRunAction->GetEventDataH1()[i][time] += totalEnergy;
            }
        }
    }
    */

/*
        for (const auto& entry : timeEnergyMap) {
                G4double time = entry.first;
                G4double totalEnergy = entry.second;
            analysisManager->FillH1((*pmtHC)[i]->GetPMTNumber(), time, totalEnergy);
            //G4cout << "Histogram " << i << " entries: " << analysisManager->GetH1(i)->entries() << G4endl;
            //G4cout << "Histogram " << (*pmtHC)[i]->GetPMTNumber() << " entries: " << analysisManager->GetH1(i)->entries() << G4endl;
            }
            //G4cout << G4endl;
            //analysisManager->FillH1(i,1);
            
    }
    if(fHitCount < 1) return;
      reconPos /= fHitCount;
    G4cout << "size? :     " << pmts << G4endl;
    G4cout << "reconPos: " << reconPos << G4endl;
    G4cout << "TotalN: " << fHitCount << G4endl;
    G4cout << "TotE : " << TotE << G4endl;
    G4cout << G4endl;
    G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;G4cout << G4endl;
  }
  */

}

