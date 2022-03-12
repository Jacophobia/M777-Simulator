//
// Created by Jacob on 3/9/2022.
//

#pragma once

#include <cmath>

class Velocity
{
public:
   Velocity(double dx = 0.0, double dy = 0.0);
   double operator / (double rhs) const;
   double operator * (const Velocity & rhs) const;
#ifndef DEBUG
private:
#endif
   double getTotalVelocity() const;

   double dx;
   double dy;
};
