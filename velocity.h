//
// Created by Jacob on 3/9/2022.
//

#pragma once
class Velocity
{
public:
   Velocity() = default;
   Velocity(double dx, double dy);
#ifndef DEBUG
private:
#endif
   double dx;
   double dy;
};
