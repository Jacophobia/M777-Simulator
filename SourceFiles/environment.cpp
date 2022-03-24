//
// Created by Jacob on 3/10/2022.
//

#include <array>
#include "../HeaderFiles/environment.h"

Environment::Environment(UserInput * input) : howitzer(input)
{
   proj.reset();
   howitzer.reset();
   ground.reset();
}

void Environment::update()
{
   proj.update();
   howitzer.update();
   ground.update();
}

void Environment::draw()
{
   proj.draw();
   ground.draw();
   howitzer.draw();
}

void Environment::reset()
{
   proj.reset();
   howitzer.reset();
   ground.reset();
}

Force Environment::getAirResistance()
{
   double altitude = proj.getAltitude();
   if (altitude < 0.0)
      throw "Invalid Input: The altitude can't be negative. There is no air resistance underground.";
   double dragCoefficient = getDragCoefficient(getMach());
   double airDensity = getAirDensity(proj.getAltitude());
   double velocitySquared = proj.getVelocity() * proj.getVelocity();
   return {0.5 * dragCoefficient * airDensity * velocitySquared * proj.getArea()};
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
            prevPair.first, prevPair.second, pair.first,
            pair.second, altitude);
      else
         prevPair = pair;
   }

   return prevPair.second;
}

Acceleration Environment::getGravitationalAcceleration(double altitude)
{
   std::array<std::pair<double, double>, 15> gravityTable({
      std::make_pair( 0,     -9.807 ),
      std::make_pair( 1000,  -9.804 ),
      std::make_pair( 2000,  -9.801 ),
      std::make_pair( 3000,  -9.797 ),
      std::make_pair( 4000,  -9.794 ),
      std::make_pair( 5000,  -9.791 ),
      std::make_pair( 6000,  -9.788 ),
      std::make_pair( 7000,  -9.785 ),
      std::make_pair( 8000,  -9.782 ),
      std::make_pair( 9000,  -9.779 ),
      std::make_pair( 10000, -9.776 ),
      std::make_pair( 15000, -9.761 ),
      std::make_pair( 20000, -9.745 ),
      std::make_pair( 25000, -9.730 )
   });
   std::pair<double, double> prevPair = gravityTable.at(0);
   if (altitude < prevPair.first)
      return {0.0, prevPair.second};
   for (const std::pair<double, double>& pair : gravityTable)
   {
      if (pair.first == altitude)
         return {0.0, pair.second};
      if (pair.first > altitude && prevPair.first < altitude)
         return {0.0, getLinearInterpolation(
               prevPair.first, prevPair.second, pair.first,
               pair.second, altitude)};
      else
         prevPair = pair;
   }

   return {0.0, prevPair.second};
}

double Environment::getAirDensity(double altitude)
{
   std::array<std::pair<double, double>, 20> airDensityTable({
      std::make_pair(     0,	1.2250000 ),
      std::make_pair(  1000,	1.1120000 ),
      std::make_pair(  2000,	1.0070000 ),
      std::make_pair(  3000,	0.9093000 ),
      std::make_pair(  4000,	0.8194000 ),
      std::make_pair(  5000,	0.7364000 ),
      std::make_pair(  6000,	0.6601000 ),
      std::make_pair(  7000,	0.5900000 ),
      std::make_pair(  8000,	0.5258000 ),
      std::make_pair(  9000,	0.4671000 ),
      std::make_pair( 10000,	0.4135000 ),
      std::make_pair( 15000,	0.1948000 ),
      std::make_pair( 20000,	0.0889100 ),
      std::make_pair( 25000,	0.0400800 ),
      std::make_pair( 30000,	0.0184100 ),
      std::make_pair( 40000,	0.0039960 ),
      std::make_pair( 50000,	0.0010270 ),
      std::make_pair( 60000,	0.0003097 ),
      std::make_pair( 70000,	0.0000828 ),
      std::make_pair( 80000,	0.0000185 )
   });
   std::pair<double, double> prevPair = airDensityTable.at(0);
   if (altitude < prevPair.first)
      return prevPair.second;
   for (const std::pair<double, double>& pair : airDensityTable)
   {
      if (pair.first == altitude)
         return pair.second;
      if (pair.first > altitude && prevPair.first < altitude)
         return getLinearInterpolation(
               prevPair.first, prevPair.second, pair.first,
               pair.second, altitude);
      else
         prevPair = pair;
   }

   return prevPair.second;
}

double Environment::getDragCoefficient(double mach)
{
   std::array<std::pair<double, double>, 16> machTable({
         std::make_pair( 0.300 , 0.1629 ),
         std::make_pair( 0.500 , 0.1659 ),
         std::make_pair( 0.700 , 0.2031 ),
         std::make_pair( 0.890 , 0.2597 ),
         std::make_pair( 0.920 , 0.3010 ),
         std::make_pair( 0.960 , 0.3287 ),
         std::make_pair( 0.980 , 0.4002 ),
         std::make_pair( 1.000 , 0.4258 ),
         std::make_pair( 1.020 , 0.4335 ),
         std::make_pair( 1.060 , 0.4483 ),
         std::make_pair( 1.240 , 0.4064 ),
         std::make_pair( 1.530 , 0.3663 ),
         std::make_pair( 1.990 , 0.2897 ),
         std::make_pair( 2.870 , 0.2297 ),
         std::make_pair( 2.890 , 0.2306 ),
         std::make_pair( 5.000 , 0.2656 )
   });
   std::pair<double, double> prevPair = machTable.at(0);
   if (mach < prevPair.first)
      return prevPair.second;
   for (const std::pair<double, double>& pair : machTable)
   {
      if (pair.first == mach)
         return pair.second;
      if (pair.first > mach && prevPair.first < mach)
         return getLinearInterpolation(
               prevPair.first, prevPair.second, pair.first,
               pair.second, mach);
      else
         prevPair = pair;
   }

   return prevPair.second;
}

double Environment::getMach()
{
   return proj.getVelocity() / getSpeedOfSound(proj.getAltitude());
}
