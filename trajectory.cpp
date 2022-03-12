#include "trajectory.h"

Trajectory::Trajectory(Velocity velocity, Acceleration acceleration, Position position)
{
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->position = position;
}

Position Trajectory::getPosition()
{
	return position;
}

void Trajectory::incrementTime(Seconds second)
{
	return;
}


void Trajectory::addAcceleration(Acceleration accelerationToAdd)
{
	acceleration += accelerationToAdd;
}
