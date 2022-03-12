//
// Created by Jacob on 3/9/2022.
//

#pragma once
class Velocity
{
public:
   Velocity() = default;
   Velocity(double dx, double dy);

   Velocity operator += (Acceleration acc);        // all these operators need to be implemented.
   double operator* (Velocity velocity);
   Velocity operator+(Velocity velocity);
   Velocity operator*(double velocity);
#ifndef DEBUG
private:
#endif
   double dx;
   double dy;
};
