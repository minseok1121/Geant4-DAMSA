#include "RunAction.hh"
#include "Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

// Constructor
RunAction::RunAction(G4int clusterId, G4int procId)
    : G4UserRunAction(), fClusterId(clusterId), fProcId(procId)
{
    // Constructor body can remain empty
}

// Destructor
RunAction::~RunAction()
{
    // No need for specific cleanup of vectors
}

// Begin of Run Action
void RunAction::BeginOfRunAction(const G4Run*)
{
if (!G4Threading::IsMasterThread()) return;
G4cout << "AM I IN?" << G4endl;
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetDefaultFileType("root");
    analysisManager->SetFileName("Little" + std::to_string(fClusterId) + "_" + std::to_string(fProcId));  // Set file name for histograms
    analysisManager->SetVerboseLevel(0);

    // Create histograms
    G4int nbins = 10000;
    G4double vmin = 0.;
    G4double vmax = 1000.;

    for (size_t i = 0; i < 400; i++) {
        G4String histName = "TimeEnergyHistogram_" + std::to_string(i);
        G4String plotName = "Energy vs Time_" + std::to_string(i);
        analysisManager->CreateH1(histName, plotName, nbins, vmin, vmax);
    }

    analysisManager->CreateH2("EnteringECAL_e-", "EnteringECAL_e-", 
                              10, -5, 5,  // x-axis: PMT x position
                              10, -5, 5);
    analysisManager->CreateH2("EnteringECAL_e+", "EnteringECAL_e+", 
                              10, -5, 5,  // x-axis: PMT x position
                              10, -5, 5);
    analysisManager->CreateH2("EnteringECAL_gamma", "EnteringECAL_gamma", 
                              10, -5, 5,  // x-axis: PMT x position
                              10, -5, 5);
    analysisManager->CreateH2("EnteringECAL_neutron", "EnteringECAL_neutron", 
                              10, -5, 5,  // x-axis: PMT x position
                              10, -5, 5);

    for (size_t i = 0; i < 4; i++) {
        G4String histName = "EnergyMap_" + std::to_string(i);
        G4String plotName = "Energy at PMT_" + std::to_string(i);
        analysisManager->CreateH2(histName, plotName, 
                                  10, -5, 5,  // x-axis: PMT x position
                                  10, -5, 5);
    }

    analysisManager->OpenFile();
}

// End of Run Action
void RunAction::EndOfRunAction(const G4Run* run)
{
    if (!G4Threading::IsMasterThread()) return;
    G4cout << "In master thread. Running EndOfRunAction." << G4endl;
    
    const Run* myRun = static_cast<const Run*>(run);
    
    // Analysis 작업
    auto analysisManager = G4AnalysisManager::Instance();

    // Fill histograms
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            for (size_t k = 0; k < 10; ++k) {
                // Recover original positions
                double posX = j - 4.5;
                double posY = k - 4.5;
                analysisManager->FillH2(i, posX, posY, myRun->GetEventDataH2()[i][j][k]);
            }
        }
    }

    for (size_t i = 0; i < 400; ++i) {
        for (size_t j = 0; j < 10000; ++j) {
            analysisManager->FillH1(i, j, myRun->GetEventDataH1()[i][j]);
        }
    }

    analysisManager->Write();
    analysisManager->CloseFile();
}


// Generate Run
G4Run* RunAction::GenerateRun() {
    return new Run();
}

void RunAction::StoreKineticEnergy(int particleIndex, int binX, int binY, G4double kineticEnergy) {
    Run* fRun = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    fRun->StoreKineticEnergy(particleIndex, binX, binY, kineticEnergy);
}