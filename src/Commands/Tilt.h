#ifndef TILT_H
#define TILT_T

#include "../CommandBase.h"
#include "WPILib.h"

class Tilt: public CommandBase
{
private:
	bool limitEstablished;
public:
	Tilt();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
