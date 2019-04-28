#include "LeanBack.h"
#include "../RobotMap.h"
#include "../Commands/Tilt.h"

LeanBack::LeanBack() :
		Subsystem("LeanBack"),
		frontSwitch(9),backSwitch(8),
		tiltMotor(6),gyro(1)
{
gyro.InitGyro();
}

void LeanBack::InitDefaultCommand()
{
	SetDefaultCommand(new Tilt());
}

bool LeanBack::GetBackSwitch(){
	bool backSwitchState = backSwitch.Get();
	SmartDashboard::PutBoolean("Back Switch", backSwitchState);
	return backSwitchState;
}

bool LeanBack::GetFrontSwitch(){
	bool frontSwitchState = frontSwitch.Get();
	SmartDashboard::PutBoolean("Front Switch", frontSwitchState);
	return frontSwitchState;
}

void LeanBack::SetMotorSpeed(float victorSpeed){
	tiltMotor.Set(victorSpeed);
	SmartDashboard::PutNumber("Tilt Speed", victorSpeed);
}

float LeanBack::getGyroAngle()
{
  int gyroAngle = (int)((360.0/344.0) * gyro.GetAngle()); // tested full rotation at 344 degrees, ratio is to correct error.
  gyroAngle = (gyroAngle % 360);  //reduce angle to a 360 degree range
  SmartDashboard::PutNumber("Gyro Angle", gyroAngle);
  return gyroAngle;
}

void LeanBack::resetGyro()
{
	gyro.Reset();
}
