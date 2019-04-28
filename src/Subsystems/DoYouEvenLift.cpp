#include "DoYouEvenLift.h"
#include "../RobotMap.h"
#include "../Commands/Lifter.h"

DoYouEvenLift::DoYouEvenLift() :
		Subsystem("DoYouEvenLift"),
		bottomSwitch(7),topSwitch(6),
		liftMotor(5),liftMotor2(7),
		liftEncoder(5, 4, false, Encoder::k4X)
{

}

void DoYouEvenLift::InitDefaultCommand()
{
	SetDefaultCommand(new Lifter());
}

bool DoYouEvenLift::GetBottomSwitch(){
	bool bottomSwitchState = bottomSwitch.Get();
	SmartDashboard::PutBoolean("Bottom Switch", bottomSwitchState);
	return bottomSwitchState;
}

bool DoYouEvenLift::GetTopSwitch(){
	bool topSwitchState = topSwitch.Get();
	SmartDashboard::PutBoolean("Top Switch", topSwitchState);
	return topSwitchState;
}

void DoYouEvenLift::SetMotorSpeed(float victorSpeed){
	liftMotor.Set(victorSpeed);
	SmartDashboard::PutNumber("Elevation Speed", victorSpeed);
}

void DoYouEvenLift::SetMotor2Speed(float victor2Speed){
	liftMotor2.Set(victor2Speed);
	SmartDashboard::PutNumber("Elevation Speed 2", victor2Speed);
}

double DoYouEvenLift::GetEncoderDistance(){
	double elevationDistance = -liftEncoder.GetDistance();
	SmartDashboard::PutNumber("Elevation Distance", elevationDistance);
	return elevationDistance;
}

void DoYouEvenLift::resetEncoder()
{
	liftEncoder.Reset();
}

