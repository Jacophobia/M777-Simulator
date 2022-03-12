#pragma once
#include "velocity.h"
#include "acceleration.h"

class Seconds
{
public:
	Velocity operator*(Acceleration acc);
private:
	double seconds;
};