//
// Created by Jacob on 3/12/2022.
//

#pragma once

#include "acceleration.h"
#include "force.h"

class Mass
{
public:
   Mass(double kgs = 0.0);
//   Force operator*(Acceleration acc);
   double getKgs();
private:
   double kgs;
};

