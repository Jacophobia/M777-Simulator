//
// Created by Jacob on 3/10/2022.
//

#include "environment.h"

Environment::Environment()
{

}

void Environment::update()
{

}

void Environment::draw()
{

}

void Environment::reset()
{

}

Force Environment::getAirResistance()
{
   return Force();
}

double Environment::getLinearInterpolation(double d0, double r0, double d1, double r1, double d)
{
   return 0;
}

double Environment::getSpeedOfSound(double altitude)
{
   return 0;
}

Acceleration Environment::getGravitationalAcceleration(double altitude)
{
   return Acceleration();
}

double Environment::getAirDensity(double altitude)
{
   return 0;
}

double Environment::getDragCoefficient(double mach)
{
   return 0;
}

double Environment::getMach()
{
   return 0;
}
