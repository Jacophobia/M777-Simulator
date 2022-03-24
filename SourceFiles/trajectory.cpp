#include "../HeaderFiles/trajectory.h"
#include <cmath>

Trajectory::Trajectory(Position position, double angle)
{
	
	
	this->position = position;
	this->angle = angle;

	double vInit = 827;
	double xVInit = 827 * sin(this->angle);
	double yVInit = 827 * cos(this->angle);

	velocity.set(xVInit, yVInit);
}

Position Trajectory::getPosition()
{
	return position;
}

void Trajectory::incrementTime(Seconds second)
{
	
	// many stuffs go here



	return;
}


// need many more functions here to have increment time call

void Trajectory::addAcceleration(Acceleration accelerationToAdd)
{
	acceleration += accelerationToAdd;
}
