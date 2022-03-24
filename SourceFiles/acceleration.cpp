#pragma once

#include "../HeaderFiles/acceleration.h"
#include <cmath>

Acceleration::Acceleration(double xAcceleration, double yAcceleration)
{
	ddx = xAcceleration;
	ddy = yAcceleration;
}

double Acceleration::getTotalAcceleration() const
{
	return sqrt((ddy * ddy) + (ddx * ddx));

}

double Acceleration::getDDX()
{
		return this->ddx;
}

double Acceleration::getDDY()
{
		return this->ddy;
}

Acceleration Acceleration::operator+=(Acceleration acceleration)
{
	ddx += acceleration.ddx;
   ddy += acceleration.ddy;

	return *this;
}
