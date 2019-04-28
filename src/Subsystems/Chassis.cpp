#include "Chassis.h"
#include "../Commands/drivewithJoystick.h"
#include "../RobotMap.h"
#include "../OI.h"

Chassis::Chassis() :
		Subsystem("Chassis"),
m_front_left(frontLeftChannel),
m_front_right(frontRightChannel),
m_rear_left(rearLeftChannel),
m_rear_right(rearRightChannel),
robotDrive(m_front_left, m_rear_left, m_front_right, m_rear_right),
stick(joystickChannel)
{
	//robotDrive.SetExpiration(0.5);//set from 0.1 to 0.5 to fix timeout while driving
	robotDrive.SetSafetyEnabled(false);

	m_front_left.setName("Front Left Motor");
	m_front_right.setName("Front Right Motor");
	m_rear_left.setName("Rear Left Motor");
	m_rear_right.setName("Rear Right Motor");
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
SetDefaultCommand(new DriveWithJoystick());
}

void Chassis::MecanumCartesian(float x, float y, float twist, float gyroAngle){
//	printf("chassis mecanum cartesian called with %f %f %f %f",x,y,twist,gyroAngle);
	robotDrive.MecanumDrive_Cartesian(x,y,twist,gyroAngle);
}

void Chassis::SetMotorRatios(float frontLeftRatio, float rearLeftRatio,
							 float frontRightRatio, float rearRightRatio)
{
	m_front_left.setRatio(frontLeftRatio);
	m_rear_left.setRatio(rearLeftRatio);
	m_front_right.setRatio(frontRightRatio);
	m_rear_right.setRatio(rearRightRatio);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
// here. Call these from Commands.

