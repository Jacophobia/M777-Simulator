#include "mass.h"

Mass::Mass(double kgs)
{
	this->kgs = kgs;
}

Force Mass::operator*(Acceleration acc)
{
	double mass = this->getKgs();
	double accl = acc.getTotalAcceleration();
	double force = mass * accl;
	return Force(force);
}

double Mass::getKgs()
{
	return this->kgs;
}
