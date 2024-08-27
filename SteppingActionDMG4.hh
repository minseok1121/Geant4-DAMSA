#pragma once

#include "G4UserSteppingAction.hh"
#include "globals.hh"

#include "G4ThreeVector.hh"
#include "G4OpBoundaryProcess.hh"

class DetectorConstruction;
class EventAction;


class SteppingActionDMG4 : public G4UserSteppingAction
{
  public:
    SteppingActionDMG4(DetectorConstruction* myDC, EventAction* myEA, G4int clusterId, G4int procId);
    virtual ~SteppingActionDMG4(){};

    virtual void UserSteppingAction(const G4Step*);
    
    virtual void Reset();

    virtual void Finalize();

  private:

    EventAction* eventAction;
    G4ThreeVector fInitialPosition;
    G4int fClusterId;
    G4int fProcId;

    G4OpBoundaryProcess* fBoundary = nullptr;
};
