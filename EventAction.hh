#pragma once

#include "G4UserEventAction.hh"
#include <mutex> // C++11 mutex
#include <vector>
#include <map>
#include "G4ThreeVector.hh"

class DetectorConstruction;
class SteppingActionDMG4;
class DarkMatter;
class G4Event;
class RunAction;

class EventAction : public G4UserEventAction
{
public:
    EventAction(DetectorConstruction* myDC, DarkMatter* DMPointer, RunAction* runAction);
    ~EventAction();

public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    void SetSteppingAction(SteppingActionDMG4* action) { theSteppingAction = action; }
    DarkMatter* GetDarkMatterPointer() { return myDarkMatter; }
    G4int GetEventID() const { return fEventID; }
    void AddKineticEnergy(int particleIndex, int binX, int binY, G4double kineticEnergy) {
        eventDataH2[particleIndex][binX][binY] += kineticEnergy;
    }

private:
    DetectorConstruction* myDetector;
    SteppingActionDMG4* theSteppingAction;
    DarkMatter* myDarkMatter;
    int fEventCounter; // Changed to 'int' from 'G4int'
    int NEmissions;    // Changed to 'int' from 'G4int'

    std::mutex eventMutex; // C++11 mutex for thread safety
    G4int fEventID;

    G4int fPMTCollID = -1;
    G4int fHitCount = 0;

    RunAction* fRunAction;

    std::vector<std::vector<std::vector<G4double>>> eventDataH2;
};