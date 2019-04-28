#ifndef SRC_COMMANDS_AUTOELEVATOR_H_
#define SRC_COMMANDS_AUTOELEVATOR_H_

#include "../CommandBase.h"
#include "WPILib.h"

#define AUTO_ELEVATOR_SPEED .5


class AutoElevator: public CommandBase{
private:
	AutoElevator(){};
	int direction;
	bool finished;
public:
	AutoElevator(int direction);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
