#pragma once
#include "acceleration.h"
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
	double ddx = this->ddx;
	double ddy = this->ddy;

	double ddxToAdd = acceleration.ddx;
	double ddyToAdd = acceleration.ddy;

	double newddx = ddx + ddxToAdd;
	double newddy = ddy + ddyToAdd;

	return Acceleration(newddx,newddy);
}
