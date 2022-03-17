#pragma once
#include "velocity.h"
#include "acceleration.h"

class Seconds
{
public:
	Velocity operator*(Acceleration acc);

#ifndef DEBUG
private:
#endif
	double seconds;
};