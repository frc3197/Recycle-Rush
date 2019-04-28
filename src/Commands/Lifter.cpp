#include "Lifter.h"

Lifter::Lifter():
  limitEstablished(false)
{
	Requires(doYouEvenLift);
}

// Called just before this Command runs the first time
void Lifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Lifter::Execute()
{
	//Assuming here that switches are false when not sensing anything
	//Assuming also that elevationSpeed is positive when traveling up
	float elevationSpeed = oi->getElevation();
	double encoderDistance= doYouEvenLift->GetEncoderDistance();

	SmartDashboard::PutBoolean("Lifter Limit Established", limitEstablished);

	if ((doYouEvenLift->GetBottomSwitch() == false) && (elevationSpeed < 0))
	{
		elevationSpeed = 0;
		limitEstablished = true;
		doYouEvenLift->resetEncoder();
	}
	else if ((doYouEvenLift->GetTopSwitch() == false) && (elevationSpeed > 0))
	{
		elevationSpeed = 0;
	}

	if ((false == limitEstablished) ||
		((encoderDistance < BOTTOM_LIMIT) && (elevationSpeed < 0)) ||
		((encoderDistance > TOP_LIMIT) && (elevationSpeed > 0)))
	{
		elevationSpeed/= SLOW_RATIO;
	}

	doYouEvenLift->SetMotorSpeed(elevationSpeed);
	doYouEvenLift->SetMotor2Speed(elevationSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool Lifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Lifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lifter::Interrupted()
{

}
