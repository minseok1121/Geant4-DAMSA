#include "Run.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "PMTSD.hh"
#include "G4SDManager.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

Run::Run() : G4Run()
{
}

Run::~Run()
{
    // Destructor
}

void Run::RecordEvent(const G4Event* event)
{
    G4Run::RecordEvent(event);

    G4HCofThisEvent* hitsCE  = event->GetHCofThisEvent();
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    if(fPMTCollID < 0) fPMTCollID = SDman->GetCollectionID("pmtHitCollection");

    PMTHitsCollection* pmtHC = nullptr;
    if(hitsCE) {
        if(fPMTCollID >= 0)
        {
            pmtHC = (PMTHitsCollection*) (hitsCE->GetHC(fPMTCollID));
        }
    }
    size_t pmts = pmtHC->entries();
    if(!pmts) return;

    //G4cout << "PMT hits: " << pmtHC->entries() << G4endl;

    for (size_t i = 0; i < pmts; ++i)
    {
        G4ThreeVector pmtPos = (*pmtHC)[i]->GetPMTPos();
        int j = -1;
        if (pmtPos.z() == 261) j = 4;
        else if (pmtPos.z() == 371) j = 5;
        else if (pmtPos.z() == 481) j = 6;
        else if (pmtPos.z() == 591) j = 7;

        G4double posX = pmtPos.x() / cm; // Convert position to cm if needed
        G4double posY = pmtPos.y() / cm;
        int binX = static_cast<int>(posX+4.5);
        int binY = static_cast<int>(posY+4.5);

        std::map<G4double, G4double> timeEnergyMap;
        const std::vector<PhotonInfo>& photonInfos = (*pmtHC)[i]->GetPhotonInfos();
        for (const auto& info : photonInfos)
        {
            G4double realtime = info.time;
            int time = static_cast<int>((realtime / 1000.0) * 10000);
            G4double energy = info.energy;

            eventDataH2[j][binX][binY] += energy;

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
                eventDataH1[100*(j-4)+10*binX+binY][static_cast<size_t>(time)] += totalEnergy;
        }
    }

    // Process stored kinetic energy data
    
    for (size_t particleIndex = 0; particleIndex < 4; ++particleIndex) {
    for (size_t binX = 0; binX < 10; ++binX) {
        for (size_t binY = 0; binY < 10; ++binY) {
            G4double kineticEnergy = tempKineticEnergyData[particleIndex][binX][binY];
            eventDataH2[particleIndex][binX][binY] += kineticEnergy;
            tempKineticEnergyData[particleIndex][binX][binY] = 0.0;
        }
    }
}

}

void Run::Merge(const G4Run* run)
{
    const Run* localRun = static_cast<const Run*>(run);

const auto& localEventDataH1 = localRun->eventDataH1;
for (size_t i = 0; i < 400; ++i) {
    for (size_t j = 0; j < 10000; ++j) {
        if(!localEventDataH1[i][j]) continue;
        eventDataH1[i][j] += localEventDataH1[i][j];
    }
}

const auto& localEventDataH2 = localRun->eventDataH2;
for (size_t i = 0; i < 8; ++i) {
    for (size_t j = 0; j < 10; ++j) {
        for (size_t k = 0; k < 10; ++k) {
            if(!localEventDataH2[i][j][k]) continue;
            eventDataH2[i][j][k] += localEventDataH2[i][j][k];
        }
    }
}
    // 부모 클래스의 Merge 호출
    G4Run::Merge(localRun);
}

void Run::StoreKineticEnergy(int particleIndex, int binX, int binY, G4double kineticEnergy)
{
    tempKineticEnergyData[particleIndex][binX][binY] += kineticEnergy;
}
