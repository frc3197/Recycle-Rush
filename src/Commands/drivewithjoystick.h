#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveWithJoystick: public CommandBase
{
public:
	DriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
