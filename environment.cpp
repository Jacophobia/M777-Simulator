//
// Created by Jacob on 3/10/2022.
//

#include <array>
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

double Environment::getLinearInterpolation(double v0, double c0, double v1, double c1, double v)
{
   if (v0 == v1 || v == v0)
      return c0;
   if (v == v1)
      return c1;
   if ((v < v0 && v < v1) || (v > v0 && v > v1))
      throw "Invalid Input: v must be be between v0 and v1";
   return c0 + ((v - v0) * (c1 - c0)) / (v1 - v0);
}

double Environment::getSpeedOfSound(double altitude)
{
   // TODO: make this a binary search to improve efficiency
   const std::array<const std::pair<double, double>, 16> soundSpeedTable = {
         std::make_pair( 0.0,      340.0 ),
         std::make_pair( 1000.0,   336.0 ),
         std::make_pair( 2000.0,   332.0 ),
         std::make_pair( 3000.0,	328.0 ),
         std::make_pair( 4000.0,	324.0 ),
         std::make_pair( 5000.0,	320.0 ),
         std::make_pair( 6000.0,	316.0 ),
         std::make_pair( 7000.0,	312.0 ),
         std::make_pair( 8000.0,	308.0 ),
         std::make_pair( 9000.0,	303.0 ),
         std::make_pair( 10000.0,	299.0 ),
         std::make_pair( 15000.0,	295.0 ),
         std::make_pair( 20000.0,	295.0 ),
         std::make_pair( 25000.0,	295.0 ),
         std::make_pair( 30000.0,	305.0 ),
         std::make_pair( 40000.0,	324.0)
   };
   std::pair<double, double> prevPair;
   for (const std::pair<double, double>& pair : soundSpeedTable)
   {
      if (pair.first == altitude)
         return pair.second;
      if (pair.first > altitude && prevPair.first < altitude)
         return getLinearInterpolation(
            prevPair.first, pair.first, prevPair.second,
            pair.second, altitude);
      else
         prevPair = pair;
   }

   return 340.0;
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
