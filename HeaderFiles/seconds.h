#pragma once
#include "velocity.h"
#include "acceleration.h"

class Seconds
{
public:
	Seconds(double seconds = 0.0);
	Velocity operator*(Acceleration acc);

#ifndef DEBUG
private:
#endif
	double seconds;
};