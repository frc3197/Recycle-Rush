#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/CameraControl.h"

Camera::Camera() :
		Subsystem("Camera")
{

}

void Camera::InitDefaultCommand()
{
	SetDefaultCommand(new CameraControl());
}


