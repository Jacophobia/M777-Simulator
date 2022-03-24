#include "../HeaderFiles/velocity.h"

Velocity::Velocity(double dx, double dy) : dx(dx), dy(dy)
{
}


double Velocity::operator/(double rhs) const
{
   return getTotalVelocity() / rhs;
}

double Velocity::getTotalVelocity() const
{
   return sqrt((dy * dy) + (dx * dx));
}

double Velocity::operator*(const Velocity & rhs) const
{
   return getTotalVelocity() * rhs.getTotalVelocity();
}

void Velocity::set(double dx, double dy)
{
   this->dx = dx;
   this->dy = dy;
}
