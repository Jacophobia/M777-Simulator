//
// Created by Jacob on 3/9/2022.
//

#pragma once
#include "acceleration.h"
#include "velocity.h"
#include "projectile.h"
#include "force.h"
#include "howitzer.h"
#include "../DefaultFiles/ground.h"

class Environment
{
public:
   Environment(UserInput * input);
   void update();
   void draw();
   void reset();
#ifndef DEBUG
private:
#endif
   Force getAirResistance();
   double getLinearInterpolation(double v0, double c0, double v1, double c1, double v);
   double getSpeedOfSound(double altitude);
   Acceleration getGravitationalAcceleration(double altitude);
   double getAirDensity(double altitude);
   double getDragCoefficient(double mach);
   double getMach();

   // member variables
   Projectile proj;
   Howitzer howitzer;
   Ground ground;
   bool isProjFired;

};


