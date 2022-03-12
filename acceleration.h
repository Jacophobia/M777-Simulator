//
// Created by Jacob on 3/9/2022.
//

#pragma once

class Acceleration
{
public:
   Acceleration() = default;
   Acceleration(double xAcceleration, double yAcceleration);
   double getTotalAcceleration() const;
   double getDDX();
   double getDDY();
   
   Acceleration operator += (Acceleration acceleration);
#ifndef DEBUG
private:
#endif
   double ddx;
   double ddy;
   
   
};
