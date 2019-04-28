#include "drivewithjoystick.h"


DriveWithJoystick::DriveWithJoystick() {
	Requires(chassis);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{
	chassis->SetMotorRatios(1.0, 0.75, -1.0, -0.75);
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	float forward;
	float strafe;
	oi->getRestricted(strafe, forward);
	if (oi->driveWithGyro() == true)
	{
		chassis->MecanumCartesian(strafe,forward,oi->getTwist(),0);
	}
	else
	{
		chassis->MecanumCartesian(strafe,forward,oi->getTwist(), 0);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{

}
