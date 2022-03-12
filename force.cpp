#include "force.h"

Force::Force(double force)
{
	this->N = force;
}

double Force::operator/(Mass mass)
{
	double force = this->N;
	double kgs = mass.getKgs();
	return (force / kgs);
}

