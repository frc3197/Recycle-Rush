#include "OI.h"
#include "Math.h"
#include "Commands/AutoElevator.h"
//#define TWO_CONTROLLERS

OI::OI():
stick(JOYSTICK),
button1(&stick, BUTTON1),
button2(&stick, BUTTON2),
button3(&stick, BUTTON3),
button4(&stick, BUTTON4),
button5(&stick, BUTTON5),
button6(&stick, BUTTON6),
button7(&stick, BUTTON7),
button8(&stick, BUTTON8),
button9(&stick, BUTTON9),
button10(&stick, BUTTON10),
pickUpStick(PICKUP_STICK),
pickUpButton1(&pickUpStick, BUTTON1),
pickUpButton2(&pickUpStick, BUTTON2),
pickUpButton3(&pickUpStick, BUTTON3),
pickUpButton4(&pickUpStick, BUTTON4),
pickUpButton5(&pickUpStick, BUTTON5),
pickUpButton6(&pickUpStick, BUTTON6),
pickUpButton7(&pickUpStick, BUTTON7),
pickUpButton8(&pickUpStick, BUTTON8),
pickUpButton9(&pickUpStick, BUTTON9),
pickUpButton10(&pickUpStick, BUTTON10),

CurrentCamera(1),
Currentbutton7(false),
Currentbutton3(false),
GyroMode(false)
{
	button4.WhenPressed(new AutoElevator(1));
	button1.WhenPressed(new AutoElevator(-1));
}
static const float ROOT2OVER2 = 0.70710678118;

float OI::getForward(){

	float forwardRaw = -stick.GetY();
	if (fabs(forwardRaw - stick.GetX())<fabs(.1*stick.GetX())){
		forwardRaw = (stick.GetX()*ROOT2OVER2);//Limits to diagonal motion
	}

		/*if ((fabs(forwardRaw - stick.GetX()) < 0.1) && (fabs(forwardRaw) > 0.2))
			forwardRaw = 0.5;*/
	else if (fabs(stick.GetX())>fabs(forwardRaw)){
			forwardRaw = 0; //Limits to X/Y motion
	}
	if ((forwardRaw < .1)&&(forwardRaw > -.1)){
		forwardRaw = 0; //Dead Zone
	}
	SmartDashboard::PutNumber("Raw Forward Drive", forwardRaw);

	float forwardActual = forwardRaw * forwardRaw * forwardRaw;
	SmartDashboard::PutNumber("Actual Forward Drive", forwardActual);

	return forwardActual;
}

float OI::getStrafe(){
	float strafeRaw = stick.GetX();

	if (fabs(strafeRaw - stick.GetY())<fabs(.1*strafeRaw)){
		strafeRaw = (strafeRaw*ROOT2OVER2);//Limits to diagonal motion
	}
	/*if ((fabs(strafeRaw - stick.GetY()) < 0.1) && (fabs(strafeRaw) > 0.2))
		strafeRaw = 0.5;*/
	else if (fabs(stick.GetY())>fabs(strafeRaw)){
		strafeRaw = 0;//Limits to X/Y motion
	}
	if ((strafeRaw < .1)&&(strafeRaw > -.1)){
		strafeRaw = 0;//Dead Zone
	}
	SmartDashboard::PutNumber("Raw Strafe Drive", strafeRaw);

	float strafeActual = strafeRaw * strafeRaw * strafeRaw;
	SmartDashboard::PutNumber("Actual Strafe Drive", strafeActual);

	return strafeActual;
}
float OI::getTwist(){
	float twistLeftRaw = stick.GetRawAxis(2);
	float twistRightRaw = stick.GetRawAxis(3);
	float twist;

	if(twistLeftRaw > twistRightRaw)
	{
		twistRightRaw = 0;
		twist = -twistLeftRaw;
	}
	else if(twistRightRaw > twistLeftRaw)
	{
		twistLeftRaw = 0;
		twist = twistRightRaw;
	}
	else
	{
		twistLeftRaw = 0;
		twistRightRaw = 0;
		twist = 0;
	}
	float twistLeftActual = twistLeftRaw * 0.5;
	float twistRightActual = twistRightRaw * 0.5;

	SmartDashboard::PutNumber("Twist", twist);

	SmartDashboard::PutNumber("Raw Left Twist", twistLeftRaw);
	SmartDashboard::PutNumber("Raw Right Twist", twistRightRaw);

	SmartDashboard::PutNumber("Actual Left Twist", twistLeftActual);
	SmartDashboard::PutNumber("Actual Right Twist", twistRightActual);


	return twist/2.0;
}
unsigned int OI::getCameraNumber()
{
	bool newbutton7 = pickUpButton7.Get();

	if ((newbutton7 == true)&&Currentbutton7 == false)
	{
		if (newbutton7 == true)
		{
			if(CurrentCamera == 1)
			{
				CurrentCamera = 2;
			}
			else
			{
				CurrentCamera = 1;
			}
		}
	}
	Currentbutton7 = newbutton7;
	SmartDashboard::PutNumber("CurrentCamera", CurrentCamera);
	return CurrentCamera;
}

bool OI::resetGyro()
{
	return button8.Get();
}

bool OI::driveWithGyro()
{
	bool newbutton3 = button3.Get();
	if ((newbutton3 == true)&&Currentbutton3 == false)
	{
		if (newbutton3 == true)
		{
			if (GyroMode == false)
			{
				GyroMode = true;
			}
			else
			{
				GyroMode = false;
			}
		}
	}
	Currentbutton3 = newbutton3;
	SmartDashboard::PutBoolean("Gyro Mode", GyroMode);
	return GyroMode;
}

void OI::getRestricted(float &x, float &y)
{
	// start with raw values
	float xRaw = stick.GetX();
	float yRaw = stick.GetY();

	SmartDashboard::PutNumber("xRaw", xRaw);
	SmartDashboard::PutNumber("yRaw", yRaw);

	// get absolute values
	float xAbs = fabs(xRaw);
	float yAbs = fabs(yRaw);

	// dead zones
	if (xAbs < STICK_DEADZONE)
	{
		xRaw = 0.0;
		xAbs = 0.0;
	}
	if (yAbs < STICK_DEADZONE)
	{
		yRaw = 0.0;
		yAbs = 0.0;
	}

	if (xAbs > yAbs)
	{
		x= xRaw;
		y=0.0;
	}
	else
	{
		y= yRaw;
		x=0.0;
	}


	// boundary for restricted movement
	//const float boundry = tan(22.5);

	/*
	// avoid dividing by zero and destroying the universe
	if ((xAbs == 0) || (yAbs == 0))
	{
		// at least one is zero. We are either going in one direction
		// or both are zero.
		x = xRaw;
		y = yRaw;
	}
	else if ((yAbs / xAbs) < boundry)
	{
		// x is dominant
		x = xRaw;
		y = 0;
	}
	else if ((xAbs / yAbs) < boundry)
	{
		// y is dominant
		x = 0;
		y = yRaw;
	}
	else
	{
		// neither is dominant, 45 degrees
		float xyAvg = (xAbs + yAbs) / 2.0;
		x = xyAvg;
		y = xyAvg;

		// adjust for correct sign
		if (xRaw < 0)
			x = -x;
		if (yRaw < 0)
			y = -y;
	}*/

	SmartDashboard::PutNumber("x", x);
	SmartDashboard::PutNumber("y", y);

	x/=2.0;
	y/=1.5;
}


float OI::getTilt()
{
	#ifdef TWO_CONTROLLERS
		bool tiltForward = pickUpButton6.Get();
		bool tiltBackward = pickUpButton5.Get();
	#else
		bool tiltForward = button6.Get();
		bool tiltBackward = button5.Get();
	#endif
	float tilt;

	if ((tiltForward == true) && (tiltBackward == false))
	{
		tilt = -1.0;
	}
	else if ((tiltBackward == true) && (tiltForward == false))
	{
		tilt = 0.5;
	}
	else
	{
		tilt = 0;
	}
	return tilt;
}
float OI::getElevation()
{
	#ifdef TWO_CONTROLLERS
		float Elevation = pickUpStick.GetRawAxis(5);
	#else
		float Elevation = -(stick.GetRawAxis(5));
	#endif

	if ((Elevation < 0.1) && (Elevation > -0.1))
	{
		Elevation = 0;
	}

	SmartDashboard::PutNumber("Elevation", Elevation);
	return Elevation;
}


