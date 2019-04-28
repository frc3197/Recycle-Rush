#ifndef OI_H
#define OI_H
//#define TWO_CONTROLLERS

#include "WPILib.h"
#define STICK_DEADZONE 0.125

class OI
{
private:
	static const int JOYSTICK = 0;
	static const int BUTTON1 = 1;
	static const int BUTTON2 = 2;
	static const int BUTTON3 = 3;
	static const int BUTTON4 = 4;
	static const int BUTTON5 = 5;
	static const int BUTTON6 = 6;
	static const int BUTTON7 = 7;
	static const int BUTTON8 = 8;
	static const int BUTTON9 = 9;
	static const int BUTTON10 = 10;
	static const int PICKUP_STICK = 1;


	Joystick stick;

	JoystickButton button1; //A
	JoystickButton button2; //B
	JoystickButton button3; //X
	JoystickButton button4; //Y
	JoystickButton button5; //LB
	JoystickButton button6; //RB
	JoystickButton button7; //Back
	JoystickButton button8; //Start
	JoystickButton button9; //Left Stick Click
	JoystickButton button10; //Right Stick Click

	Joystick  pickUpStick;

	JoystickButton pickUpButton1;
	JoystickButton pickUpButton2;
	JoystickButton pickUpButton3;
	JoystickButton pickUpButton4;
	JoystickButton pickUpButton5;
	JoystickButton pickUpButton6;
	JoystickButton pickUpButton7;
	JoystickButton pickUpButton8;
	JoystickButton pickUpButton9;
	JoystickButton pickUpButton10;
	unsigned char CurrentCamera;
	bool Currentbutton7;
	bool Currentbutton3;
	bool GyroMode;


public:
	OI();
	float getForward();
	float getStrafe();
	float getTwist();
	unsigned int getCameraNumber();
	bool resetGyro();
	bool driveWithGyro();
	void getRestricted(float &x, float &y);
	float getTilt();
	float getElevation();

	bool Button1();
	bool Button2();
	bool Button3();
	bool Button4();
	bool Button5();
	bool Button6();
	bool Button7();
	bool Button8();
	bool Button9();
	bool Button10();
};

#endif
