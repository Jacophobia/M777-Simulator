#include "../HeaderFiles/seconds.h"

Seconds::Seconds(double seconds)
{
	this->seconds = seconds;
}

Velocity Seconds::operator*(Acceleration acc)
{
	double seconds = this->seconds;
	double ddx = acc.getDDX();
	double ddy = acc.getDDY();
	return Velocity((seconds * ddx),(seconds * ddy));
}
