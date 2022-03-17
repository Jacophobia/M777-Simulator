#pragma once
#include "velocity.h"
#include "acceleration.h"

class Seconds
{
public:
	Seconds(double seconds);
	Velocity operator*(Acceleration acc);

#ifndef DEBUG
private:
#endif
	double seconds;
};