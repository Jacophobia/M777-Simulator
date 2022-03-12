#pragma once
#include "force.h"

class Mass
{
public:
	Mass(double kgs);
	Force operator*(Acceleration acc);
	double getKgs();
private:
	double kgs;
};