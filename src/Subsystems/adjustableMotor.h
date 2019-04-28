/*
 * adjustableMotor.h
 *
 *  Created on: Feb 8, 2015
 *      Author: clange
 */

#ifndef ADJUSTABLEMOTOR_H_
#define ADJUSTABLEMOTOR_H_

#include "WPILib.h"
#include "string.h"

class adjustableMotor : public SpeedController
{
	float setThrottle;
	CANTalon motor;
	float motorRatio;
	std::string motorName;

	// deny use of default constructor by making private
	// assign motor to dummy can ID for compiler
	adjustableMotor():motor(0){};
public:
	// our constructor requires a can device number for the motor.
	adjustableMotor(int CANdevNum);

	// need to override these from base class (pure virtuals)

 	// Common interface for setting the speed of a speed controller. More...
	void Set(float speed, uint8_t syncGroup);

	// Common interface for getting the current set speed of a speed controller. More...
	float Get(){return setThrottle;};

	// Common interface for disabling a motor.
	// not doing anything here for now.
	void Disable(){};

	// another pure virtual we need to take care of
	void PIDWrite(float){};

	void setRatio(float pMotorRatio);
	void setName(const char * pName);
};



#endif /* ADJUSTABLEMOTOR_H_ */
