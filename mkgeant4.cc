#include "globals.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingActionDMG4.hh"

#include "QGSP_BERT.hh"
#include "FTFP_BERT.hh"

#include "DarkMatterPhysics.hh"
#include "DarkMatter.hh"

#include "G4UImanager.hh"
#include "G4UIterminal.hh"

#include "G4RunManager.hh"
#include "G4PhysListFactory.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#include "G4ios.hh"

#include "G4MTRunManager.hh"
#include "G4RunManagerFactory.hh"
#include "ActionInitialization.hh"

#include "G4OpticalPhysics.hh"

#include <atomic>

std::atomic<int> fEventCounter(0);

int main(int argc,char** argv) {

  G4int clusterId = std::stoi(argv[2]);
  G4int procId = std::stoi(argv[3]);

  // Run manager
  auto runManager =
    G4RunManagerFactory::CreateRunManager(G4RunManagerType::MT);
  
  G4int numCores = G4Threading::G4GetNumberOfCores();
    runManager->SetNumberOfThreads(1);

    std::cout << "Number of workers (threads): " << runManager->GetNumberOfThreads() << std::endl;
//G4MTRunManager* runManager = new G4MTRunManager;
  // UserInitialization classes
  DetectorConstruction* mkexp = new DetectorConstruction;
  runManager->SetUserInitialization(mkexp);

  // ___ Here the "extension" part starts ___
  G4PhysListFactory factory;
  G4VModularPhysicsList * phys = factory.GetReferencePhysList("FTFP_BERT");
  // ^^^ most of the standard physics lists are available by this interface

//  G4PhysicsListHelper * phLHelper = G4PhysicsListHelper::GetPhysicsListHelper();
//  phLHelper->DumpOrdingParameterTable();
double epsilon = 0.01;
if (argc > 1) {
    epsilon = std::stod(argv[1]);
  }

  DarkMatterPhysics* myPhysics = new DarkMatterPhysics(epsilon);
  phys->RegisterPhysics(myPhysics);
  // ^^^ Here the "extension" part ends ^^^

   G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  phys->RegisterPhysics(opticalPhysics);

  runManager->SetUserInitialization(phys);  // init phys


#ifdef G4VIS_USE
  // Visualization, if you choose to have it!
  G4VisManager* visManager = new G4VisExecutive;

  visManager->Initialize();
#endif
   
  // UserAction classes
  runManager->SetUserInitialization(new ActionInitialization(mkexp, myPhysics, clusterId, procId));
  // Initialize the run manager
  runManager->Initialize();

  //std::cout << "Total events processed: " << fEventCounter << std::endl;
/*
  runManager->SetUserAction(new PrimaryGeneratorAction(mkexp));

  EventAction* myEA = new EventAction(mkexp, myPhysics->GetDarkMatterPointer());
  runManager->SetUserAction(myEA);
  runManager->SetUserAction(new SteppingActionDMG4(mkexp, myEA));
*/
  // User interactions
  G4UImanager * UI = G4UImanager::GetUIpointer();  
 
  UI->ApplyCommand("/control/execute cardg.g4mac");
 

#ifdef G4VIS_USE
  delete visManager;
#endif
  delete runManager;

  return 0;
}
