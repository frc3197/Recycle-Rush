#ifndef LIFTER_H
#define LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

#define SLOW_RATIO 4
#define TOP_LIMIT 38000
#define BOTTOM_LIMIT 3500

class Lifter: public CommandBase
{
private:
	bool limitEstablished;
public:
	Lifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
