#ifndef DO_YOU_EVEN_LIFT_H
#define DO_YOU_EVEN_LIFT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DoYouEvenLift: public Subsystem
{
private:
	DigitalInput bottomSwitch;
	DigitalInput topSwitch;
	Victor liftMotor;
	Victor liftMotor2;
	Encoder liftEncoder;
public:
	DoYouEvenLift();
	void InitDefaultCommand();
	bool GetBottomSwitch();
	bool GetTopSwitch();
	void SetMotorSpeed(float victorSpeed);
	void SetMotor2Speed(float victor2Speed);
	double GetEncoderDistance();
	void resetEncoder();
};

#endif
