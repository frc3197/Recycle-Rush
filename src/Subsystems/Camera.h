#ifndef CAMERA_H
#define CAMERA_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Camera: public Subsystem
{
private:

public:
	Camera();
	void InitDefaultCommand();
};

#endif
