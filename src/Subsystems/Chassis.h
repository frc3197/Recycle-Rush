#ifndef CHASSIS_H
#define CHASSIS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "adjustableMotor.h"

class Chassis: public Subsystem
{
private:
	const static int frontLeftChannel  = 1;
	const static int frontRightChannel  = 2;
	const static int rearLeftChannel  = 3;
	const static int rearRightChannel  = 4;

	const static int joystickChannel  = 0;

	adjustableMotor m_front_left;
	adjustableMotor m_front_right;
	adjustableMotor m_rear_left;
	adjustableMotor m_rear_right;
	RobotDrive robotDrive;
	Joystick stick;



public:
	Chassis();
	void InitDefaultCommand();

	void MecanumCartesian(float strafe, float forward, float rotation, float gyroAngle);
	void SetMotorRatios(float m_front_left, float m_rear_left,
						float m_front_right, float m_rear_right);
};

#endif
