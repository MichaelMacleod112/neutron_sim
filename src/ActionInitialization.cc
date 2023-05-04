#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization() : G4VUserActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::BuildForMaster() const
{
  RunAction* run = new RunAction;
  SetUserAction(run);
}

void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);

  RunAction* run = new RunAction;
  SetUserAction(run);
  
  EventAction* event = new EventAction(run);
  SetUserAction(event);

  SteppingAction* step = new SteppingAction(event);
  SetUserAction(step);
}
