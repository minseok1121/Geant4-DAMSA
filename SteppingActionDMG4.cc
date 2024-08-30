#include "globals.hh"
#include "G4ios.hh"

#include "SteppingActionDMG4.hh"
//#include "RunAction.hh"
//#include "RunActionDMG4.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "DarkMatter.hh"
#include "DarkPhotons.hh"
#include "DarkScalars.hh"
#include "ALP.hh"

#include "DMParticles/DMParticle.hh"

#include "G4SteppingManager.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"

#include "G4ProcessManager.hh"
#include "G4ProcessType.hh"
#include "Randomize.hh"

#include "G4ParticleTypes.hh"
#include "G4DynamicParticle.hh"
#include "G4EventManager.hh"
#include "G4TrackVector.hh"
#include "G4SystemOfUnits.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Gamma.hh"

#include "G4ParticleTypes.hh"
#include "G4DynamicParticle.hh"
#include "G4EventManager.hh"
#include "G4TrackVector.hh"

#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "PMTSD.hh"

SteppingActionDMG4::SteppingActionDMG4(DetectorConstruction* myDC, EventAction* myEA, G4int clusterId, G4int procId)
: eventAction(myEA), G4UserSteppingAction(), fInitialPosition(G4ThreeVector(0., 0., 0.)),
  fClusterId(clusterId), fProcId(procId)
{
  eventAction->SetSteppingAction(this);
}


void SteppingActionDMG4::UserSteppingAction(const G4Step* step)
{
  G4Track* track = step->GetTrack();
  G4int trackID = track->GetTrackID();
  //G4double globalTime_ns = step->GetPreStepPoint()->GetGlobalTime() / 1.e-9 * second ;
  if(step->GetPreStepPoint()->GetGlobalTime() > 1*CLHEP::second) return;
  if(trackID==1) return;
  //if (!(step->GetPreStepPoint()->GetPosition().z() > -521*CLHEP::cm)) return;
  //if (!(step->GetTrack()->GetMomentumDirection().z() > 0)) return;
  //if (!(fabs(step->GetTrack()->GetMomentumDirection().x()) < 65*CLHEP::cm)) return;
  //if (!(fabs(step->GetTrack()->GetMomentumDirection().y()) < 65*CLHEP::cm)) return;

  G4String particleName = track->GetParticleDefinition()->GetParticleName();
  G4VPhysicalVolume* currentVolume = step->GetPreStepPoint()->GetTouchable()->GetVolume();
  //G4cout << currentVolume->GetName() << G4endl;
/*
  if ( ((particleName == "pi0" || particleName == "DMParticleALP") && track->GetTrackStatus() == fStopAndKill) ) {
            const std::vector<const G4Track*>* secondaries = step->GetSecondaryInCurrentStep();
            for (size_t i = 0; i < secondaries->size(); ++i) {
                const G4Track* secondary = (*secondaries)[i];
                G4String secondaryParticleName = secondary->GetDefinition()->GetParticleName();
                if(!(secondaryParticleName == "gamma")) continue;
                
                // 딸 입자의 정보 가져오기
                G4double Energy = secondary->GetKineticEnergy();
                G4ThreeVector position = secondary->GetPosition();
                G4ThreeVector direction = secondary->GetMomentumDirection();
                G4String Motherprocess = "Decay";

                // 딸 입자 정보를 파일에 출력
                std::ofstream outFile("LittleDamsa_"+particleName+"_Secondary_"+(currentVolume->GetName())+"_"+secondaryParticleName+".txt", std::ios_base::app);
                
    
                 // 시간만 높은 정밀도로 출력
    outFile << std::fixed << std::setprecision(15) << globalTime_fs << "     ";

    // 나머지 값들은 기본 정밀도로 출력
    outFile.unsetf(std::ios_base::fixed); // std::fixed 설정 해제
    outFile << std::setprecision(6); // 기본 정밀도로 설정
    
                outFile << Motherprocess << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " 
                        << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
                outFile.close();
            }
  }
  
  if (particleName == "DMParticleALP") {
  G4StepStatus status = track->GetStep()->GetPostStepPoint()->GetStepStatus();
            // If it's the first step, record the start time
            if (status == fGeomBoundary || track->GetCurrentStepNumber() == 1) {
              G4double Energy = step->GetPreStepPoint()->GetKineticEnergy();
              G4ThreeVector position = step->GetPreStepPoint()->GetPosition();
              G4ThreeVector direction = track->GetMomentumDirection();

              G4String Motherprocess = "p";
                  if (track->GetCreatorProcess() != nullptr) {
                        Motherprocess = track->GetCreatorProcess()->GetProcessName();
                      }
              
                G4double startTime = track->GetGlobalTime();
                std::ofstream outFile("LittleDamsa_ALPLIFE.txt", std::ios_base::app);
                outFile << "ALP created at time: " << startTime / ns << " ns" << std::endl;
                outFile << trackID << (currentVolume->GetName()) << "     " << Motherprocess << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " << direction.x() << "     " << direction.y() << "     " << direction.z() << "     " << track->GetMomentum().mag()/track->GetTotalEnergy() << "     " << step->GetPreStepPoint()->GetGlobalTime() << "     " << eventAction->GetEventID() << std::endl;
                outFile.close();
            }

            // Check if this is the last step before the particle decays
            if (status == fStopAndKill || track->GetTrackStatus() == fStopAndKill) {
              G4double Energy = step->GetPreStepPoint()->GetKineticEnergy();
              G4ThreeVector position = step->GetPreStepPoint()->GetPosition();
              G4ThreeVector direction = track->GetMomentumDirection();

              G4String Motherprocess = "p";
                  if (track->GetCreatorProcess() != nullptr) {
                        Motherprocess = track->GetCreatorProcess()->GetProcessName();
                      }
              
                G4double startTime = track->GetGlobalTime();
                std::ofstream outFile("LittleDamsa_ALPLIFE.txt", std::ios_base::app);
                G4double endTime = track->GetGlobalTime();
                outFile << "ALP decayed at time: " << endTime / ns << " ns" << std::endl;
                outFile << trackID << (currentVolume->GetName()) << "     " << Motherprocess << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " << direction.x() << "     " << direction.y() << "     " << direction.z() << "     " << track->GetMomentum().mag()/track->GetTotalEnergy() << "     " << step->GetPreStepPoint()->GetGlobalTime() << "     " << eventAction->GetEventID() << "     " << track->GetVelocity() << std::endl;
                outFile.close();
            }
  }
/*
  if((step->GetPostStepPoint()->GetProcessDefinedStep() != 0) && ((step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName()).find(std::string("DMProcess")) != std::string::npos)) {
            G4double Energy = step->GetPreStepPoint()->GetKineticEnergy();
            //if (!(Energy / CLHEP::MeV > 5)) return;
            G4ThreeVector position = step->GetPreStepPoint()->GetPosition();
            G4int stepNumber = track->GetCurrentStepNumber();
            G4ThreeVector direction = track->GetMomentumDirection();

            //G4StepPoint* SPointPostStep = aStep->GetPostStepPoint();
            //G4double ekin = aStep->GetTrack()->GetKineticEnergy()/GeV;
            //G4double ekinprestep = SPointPreStep->GetKineticEnergy()/GeV;
            //G4ParticleDefinition* theParticleDefinition = step->GetTrack()->GetDefinition();
            G4String Motherprocess = "p";
          if (track->GetCreatorProcess() != nullptr) {
                Motherprocess = track->GetCreatorProcess()->GetProcessName();
          }

          std::ofstream outFile("LittleDamsa_"+(currentVolume->GetName())+"_DMgamma.txt", std::ios_base::app);
                outFile << Motherprocess << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " 
                        << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
          const std::vector<const G4Track*>* secondaries = step->GetSecondaryInCurrentStep();
            for (size_t i = 0; i < secondaries->size(); ++i) {
                const G4Track* secondary = (*secondaries)[i];
                G4String secondaryParticleName = secondary->GetDefinition()->GetParticleName();
                //if(!(secondaryParticleName == "gamma")) continue;
                
                // 딸 입자의 정보 가져오기
                G4double Energy = secondary->GetKineticEnergy();
                G4ThreeVector position = secondary->GetPosition();
                G4ThreeVector direction = secondary->GetMomentumDirection();
                outFile << secondaryParticleName << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " 
                        << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
  }
  outFile.close();
  }
  */

  // 광자인 경우 처리
  /*
    if (particleName == "gamma" && currentVolume->GetName() == "target" && step->GetPreStepPoint()->GetKineticEnergy() > 103) {
        G4StepPoint* preStepPoint = step->GetPreStepPoint();
        G4StepPoint* postStepPoint = step->GetPostStepPoint();

        G4ThreeVector startPosition = preStepPoint->GetPosition();
        G4ThreeVector endPosition = postStepPoint->GetPosition();
        G4double stepLength = (endPosition - startPosition).mag();

        std::ofstream outFile("LittleDamsa_gammalength_target.txt", std::ios_base::app);

        outFile << stepLength << G4endl;
        outFile.close();

    }
    */
    
//return;
//G4cout << ms << G4endl;
G4OpBoundaryProcessStatus boundaryStatus = Undefined;
  if(nullptr == fBoundary && track->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition())
  {
    //ms = 21;
    G4ProcessManager* pm = track->GetParticleDefinition()->GetProcessManager();
    G4int nprocesses = pm->GetProcessListLength();
    G4ProcessVector* pv = pm->GetProcessList();
    for(G4int i = 0; i < nprocesses; ++i)
    { //G4cout << (*pv)[i]->GetProcessName() << G4endl;
      if(nullptr != (*pv)[i] && (*pv)[i]->GetProcessName() == "OpBoundary")
      {
        //G4cout << (*pv)[i]->GetProcessName() << G4endl;
        fBoundary = dynamic_cast<G4OpBoundaryProcess*>((*pv)[i]);
        break;
      }
    }
  }
//G4cout << ms << G4endl;
//G4cout << "hitTime: " << step->GetPostStepPoint()->GetGlobalTime() << G4endl;
  if(track->GetParticleDefinition() == G4OpticalPhoton::OpticalPhotonDefinition())
  { 
    if(nullptr != fBoundary) boundaryStatus = fBoundary->GetStatus();
      //G4cout << GetBoundaryStatusString(boundaryStatus) << G4endl;

    if(step->GetPostStepPoint()->GetStepStatus() == fGeomBoundary)
    {
      switch(boundaryStatus)
      {
        case Absorption:
        //G4cout << "Absorption," << boundaryStatus << G4endl;
          break;
        case Detection:  // Note, this assumes that the volume causing detection
                         // is the photocathode because it is the only one with
                         // non-zero efficiency
        {//G4cout << "Detection," << boundaryStatus << G4endl;
          // Trigger sensitive detector manually since photon is
          // absorbed but status was Detection
          G4SDManager* SDman = G4SDManager::GetSDMpointer();
          G4String sdName    = "/Det/pmtSD";
          PMTSD* pmtSD    = (PMTSD*) SDman->FindSensitiveDetector(sdName);
          if(pmtSD)
            pmtSD->ProcessHits_boundary(step, nullptr);
          break;
        }
        case FresnelReflection:
        case TotalInternalReflection:
        case LambertianReflection:
        case LobeReflection:
        case SpikeReflection:
        case BackScattering:
          break;
        default:
          break;
      }
    }
  }


  if (!(step->IsFirstStepInVolume())) return;
  G4double Energy = step->GetPreStepPoint()->GetKineticEnergy();
  //if (!(Energy / CLHEP::MeV > 5)) return;
  G4ThreeVector position = step->GetPreStepPoint()->GetPosition();
  G4int stepNumber = track->GetCurrentStepNumber();
  G4ThreeVector direction = track->GetMomentumDirection();

  G4String Motherprocess = "p";
if (track->GetCreatorProcess() != nullptr) {
      Motherprocess = track->GetCreatorProcess()->GetProcessName();
          }
/*
  if( ((step->GetPostStepPoint()->GetProcessDefinedStep() != 0) && ((step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName()).find(std::string("DMProcess")) != std::string::npos)) 
  || Motherprocess.find(std::string("DMProcess")) != std::string::npos 
  || (particleName == "gamma" && Motherprocess == "Decay") ){
*/
  //if( Motherprocess.find(std::string("DMProcess")) != std::string::npos 
  //|| (particleName == "gamma" && Motherprocess == "Decay") ){
//if(particleName == "DMParticleALP") {
  //G4cout << particleName << " production at E = " << Energy << G4endl;
   //if(!(particleName == "DMParticleALP" || particleName == "proton" || particleName == "neutron" || particleName == "gamma" || particleName == "e-" || particleName == "e+" || particleName == "pi+" || particleName == "pi-" || particleName == "pi0")) return;
    if (! (currentVolume->GetName() == "ECAL" || particleName == "DMParticleALP")) return;
    //if (!(particleName == "DMParticleALP" || (particleName == "gamma" && currentVolume->GetName() == "ECAL"))) return;
        //G4double energyDeposition = step->GetTotalEnergyDeposit();
        //G4double zPosition = step->GetPreStepPoint()->GetPosition().z();
        //G4String processName = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
        /*
        G4String parentName = "P";
        if (track->GetParentID() > 0) {
            // 모 입자의 트랙 정보를 얻습니다
            const G4Track* parentTrack = step->GetTrack()->GetParentTrack();
            if (parentTrack) {
                parentName = parentTrack->GetDefinition()->GetParticleName();
            }
        }
        */
        std::ofstream outFile("LittleDamsa_"+std::to_string(fClusterId)+"_"+std::to_string(fProcId)+"_"+(currentVolume->GetName())+"_"+particleName+".txt", std::ios_base::app);
        /*
        outFile << Motherprocess << "     " << parentName << "     " << Energy << "     " << track->GetTotalEnergy() << "     "
                << position.x() << "     " << position.y() << "     " << position.z() << "     " << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
        */
    /*
         // 시간만 높은 정밀도로 출력
    outFile << std::fixed << std::setprecision(15) << globalTime_fs << "     ";

    // 나머지 값들은 기본 정밀도로 출력
    outFile.unsetf(std::ios_base::fixed); // std::fixed 설정 해제
    outFile << std::setprecision(6); // 기본 정밀도로 설정
    */
        outFile << Motherprocess << "     " << Energy << "     "
                << position.x() << "     " << position.y() << "     " << position.z() << "     " << direction.x() << "     " << direction.y() << "     " << direction.z() << "     " << track->GetMomentum().mag()/track->GetTotalEnergy() << "     " << step->GetPreStepPoint()->GetGlobalTime() << "     " << eventAction->GetEventID() << "     " << track->GetVelocity() << std::endl;
      //outFile << particleName << " production at E = " << Energy << G4endl;
        outFile.close();
  }
//}


void SteppingActionDMG4::Reset()
{
  eventAction->GetDarkMatterPointer()->ResetNEmissions();
}


void SteppingActionDMG4::Finalize()
{
}

std::string SteppingActionDMG4::GetBoundaryStatusString(G4OpBoundaryProcessStatus status) {
    switch (status) {
        case Undefined:
            return "Undefined";
        case Transmission:
            return "Transmission";
        case FresnelRefraction:
            return "FresnelRefraction";
        case FresnelReflection:
            return "FresnelReflection";
        case TotalInternalReflection:
            return "TotalInternalReflection";
        case LambertianReflection:
            return "LambertianReflection";
        case LobeReflection:
            return "LobeReflection";
        case SpikeReflection:
            return "SpikeReflection";
        case BackScattering:
            return "BackScattering";
        case Absorption:
            return "Absorption";
        case Detection:
            return "Detection";
        case NotAtBoundary:
            return "NotAtBoundary";
        case SameMaterial:
            return "SameMaterial";
        case StepTooSmall:
            return "StepTooSmall";
        case NoRINDEX:
            return "NoRINDEX";
        default:
            return "Unknown";
    }
}