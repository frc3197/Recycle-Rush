#include "AutoElevator.h"

AutoElevator::AutoElevator(int pdirection):
direction(pdirection),
finished(false)
{
	Requires(doYouEvenLift);
	if ((pdirection!=-1)&&(pdirection!=1))
	{
		pdirection=0;
		finished = true;
	}
}

// Called just before this Command runs the first time
void AutoElevator::Initialize()
{
	finished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoElevator::Execute()
{
	doYouEvenLift->SetMotorSpeed(AUTO_ELEVATOR_SPEED * direction);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoElevator::IsFinished()
{
	if((direction == 1)&& doYouEvenLift->GetTopSwitch())
	{
		finished = true;
	}
	else if ((direction == -1)&& doYouEvenLift->GetBottomSwitch())
	{
		finished = true;
	}

	SmartDashboard::PutBoolean("AutoElevator finished", finished);
	SmartDashboard::PutNumber("AutoElevator direction", direction);

	return finished;
}

// Called once after isFinished returns true
void AutoElevator::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoElevator::Interrupted()
{

}





