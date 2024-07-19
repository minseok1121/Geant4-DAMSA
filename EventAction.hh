#pragma once

#include "G4UserEventAction.hh"
#include <mutex> // C++11 mutex

class DetectorConstruction;
class SteppingActionDMG4;
class DarkMatter;
class G4Event;

class EventAction : public G4UserEventAction
{
public:
    EventAction(DetectorConstruction* myDC, DarkMatter* DMPointer);
    ~EventAction();

public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    void SetSteppingAction(SteppingActionDMG4* action) { theSteppingAction = action; }
    DarkMatter* GetDarkMatterPointer() { return myDarkMatter; }
    

private:
    DetectorConstruction* myDetector;
    SteppingActionDMG4* theSteppingAction;
    DarkMatter* myDarkMatter;
    int fEventCounter; // Changed to 'int' from 'G4int'
    int NEmissions;    // Changed to 'int' from 'G4int'

    std::mutex eventMutex; // C++11 mutex for thread safety
};
