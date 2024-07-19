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

SteppingActionDMG4::SteppingActionDMG4(DetectorConstruction* myDC, EventAction* myEA)
: eventAction(myEA), G4UserSteppingAction(), fInitialPosition(G4ThreeVector(0., 0., 0.))
{
  eventAction->SetSteppingAction(this);
}


void SteppingActionDMG4::UserSteppingAction(const G4Step* step)
{
  G4Track* track = step->GetTrack();
  G4int trackID = track->GetTrackID();
  G4double globalTime_fs = step->GetPreStepPoint()->GetGlobalTime() / 1.e-15 * second ;
  if(step->GetPreStepPoint()->GetGlobalTime() > 1*CLHEP::second) return;
  if(trackID==1) return;
  //if (!(step->GetPreStepPoint()->GetPosition().z() > -521*CLHEP::cm)) return;
  //if (!(step->GetTrack()->GetMomentumDirection().z() > 0)) return;
  //if (!(fabs(step->GetTrack()->GetMomentumDirection().x()) < 65*CLHEP::cm)) return;
  //if (!(fabs(step->GetTrack()->GetMomentumDirection().y()) < 65*CLHEP::cm)) return;

  G4String particleName = track->GetParticleDefinition()->GetParticleName();
  G4VPhysicalVolume* currentVolume = track->GetVolume();

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
    /*
                 // 시간만 높은 정밀도로 출력
    outFile << std::fixed << std::setprecision(15) << globalTime_fs << "     ";

    // 나머지 값들은 기본 정밀도로 출력
    outFile.unsetf(std::ios_base::fixed); // std::fixed 설정 해제
    outFile << std::setprecision(6); // 기본 정밀도로 설정
    */
                outFile << Motherprocess << "     " << Energy << "     "
                        << position.x() << "     " << position.y() << "     " << position.z() << "     " 
                        << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
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
    if (particleName == "gamma" && currentVolume->GetName() == "target") {
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
  if (!(step->IsFirstStepInVolume())) return;
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
    //if (! (currentVolume->GetName() == "ECAL" || particleName == "DMParticleALP")) return;
    if (! (particleName == "DMParticleALP")) return;
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
        std::ofstream outFile("LittleDamsa_"+(currentVolume->GetName())+"_"+particleName+".txt", std::ios_base::app);
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
                << position.x() << "     " << position.y() << "     " << position.z() << "     " << direction.x() << "     " << direction.y() << "     " << direction.z() << std::endl;
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
