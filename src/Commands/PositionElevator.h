#ifndef POSITION_ELEVATOR_H
#define POSITION_ELEVATOR_H

#include "../CommandBase.h"
#include "WPILib.h"

class PositionElevator: public CommandBase
{
public:
	PositionElevator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
