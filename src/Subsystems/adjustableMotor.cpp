/*
 * adjustableMotor.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: clange
 */

#include "adjustableMotor.h"

adjustableMotor::adjustableMotor(int CANdevNum) :
motor(CANdevNum),motorRatio(1.0),motorName("unnamed")
{}

// we are not using syncGroup, just trying to match the type
// of the base class.
void
adjustableMotor::Set(float speed, uint8_t syncGroup=0)
{
	motor.Set(speed * motorRatio);
}

void adjustableMotor::setRatio(float pMotorRatio)
{
	// limit to range of 0 to 1
	if (pMotorRatio > 1.0)
		motorRatio = 1.0;
	else if (pMotorRatio < -1.0)
		motorRatio = -1.0;
	else
		motorRatio = pMotorRatio;

	std::string ratioLabel = motorName + " Ratio";
	SmartDashboard::PutNumber(ratioLabel.c_str(), motorRatio);

}

void adjustableMotor::setName(const char * pName)
{
	motorName = pName;
}

