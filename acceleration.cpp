#include "acceleration.h"
#include <cmath>
#pragma once

Acceleration::Acceleration(double xAcceleration = 0.0, double yAcceleration = 0.0)
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
	double ddx = this->ddx;
	double ddy = this->ddy;

	double ddxToAdd = acceleration.ddx;
	double ddyToAdd = acceleration.ddy;

	double newddx = ddx + ddxToAdd;
	double newddy = ddy + ddyToAdd;

	return Acceleration(newddx,newddy);
}
