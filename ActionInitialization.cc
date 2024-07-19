#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingActionDMG4.hh"

ActionInitialization::ActionInitialization(DetectorConstruction* detConstruction, DarkMatterPhysics* physics)
    : G4VUserActionInitialization(),
      fDetConstruction(detConstruction),
      fPhysics(physics)
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::BuildForMaster() const
{
    // Implement master thread actions here if needed
}

void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction(fDetConstruction));
    EventAction* eventAction = new EventAction(fDetConstruction, fPhysics->GetDarkMatterPointer());
    SetUserAction(eventAction);
    SetUserAction(new SteppingActionDMG4(fDetConstruction, eventAction));
}
