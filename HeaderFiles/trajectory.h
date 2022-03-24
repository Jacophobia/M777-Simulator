#pragma once
#include "velocity.h"
#include "acceleration.h"
#include "position.h"
#include "seconds.h"


//enum Status = {"IN_THE_AIR", "HIT_THE_GROUND", "NOT_FIRED_YET"}; // this needs work but is not needed now

class Trajectory 
{
public:
	Trajectory() = default;
	Trajectory(Position position, double angle);
	Position getPosition();
	void incrementTime(Seconds second);

#ifndef DEBUG
private:
#endif
	void addAcceleration(Acceleration accelerationToAdd);
	

	Velocity velocity;
	Acceleration acceleration;
	Position position;
   double angle;
	//Status status;
	//Point[] pastPositions; // this needs work but is also not needed now
};