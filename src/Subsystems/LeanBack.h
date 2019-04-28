#ifndef LEAN_BACK_H
#define LEAN_BACK_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LeanBack: public Subsystem
{
private:
	DigitalInput frontSwitch;
	DigitalInput backSwitch;
	Victor tiltMotor;
	Gyro gyro;
public:
	LeanBack();
	void InitDefaultCommand();
	bool GetFrontSwitch();
	bool GetBackSwitch();
	void SetMotorSpeed(float victorSpeed);
	float getGyroAngle();
	void resetGyro();
};

#endif
