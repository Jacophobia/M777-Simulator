#include "seconds.h"

Velocity Seconds::operator*(Acceleration acc)
{
	double seconds = this->seconds;
	double ddx = acc.getDDX();
	double ddy = acc.getDDY();
	return Velocity((seconds * ddx),(seconds * ddy));
}
