#include "Tilt.h"

Tilt::Tilt():
limitEstablished(false)
{
	Requires(leanBack);
}

// Called just before this Command runs the first time
void Tilt::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Tilt::Execute()
{
	float tiltSpeed = oi->getTilt();

	SmartDashboard::PutBoolean("Tilter Limit Established", limitEstablished);

	if ((leanBack->GetBackSwitch() == false) && (tiltSpeed > 0))
	{
		// we are at back limit
		leanBack->resetGyro();
		tiltSpeed = 0;
		limitEstablished = true;
	}
	else if (((leanBack->GetFrontSwitch() == false) || (!limitEstablished))
			&& (tiltSpeed < 0))
	{
		// we are at front limit OR have not established a limit
		tiltSpeed = 0;
	}
	leanBack->SetMotorSpeed(tiltSpeed);
	leanBack->getGyroAngle();
}

// Make this return true when this Command no longer needs to run execute()
bool Tilt::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Tilt::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Tilt::Interrupted()
{

}
