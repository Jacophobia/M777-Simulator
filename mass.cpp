//
// Created by Jacob on 3/12/2022.
//

#include "mass.h"

Mass::Mass(double kgs) : kgs(kgs) {}

//Force Mass::operator*(Acceleration acc)
//{
//   double mass = this->getKgs();
//   double accl = acc.getTotalAcceleration();
//   double force = mass * accl;
//   return {force};
//}

double Mass::getKgs()
{
   return this->kgs;
}

