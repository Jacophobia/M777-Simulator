//
// Created by Jacob on 3/9/2022.

#include "mass.h"
#include "acceleration.h"

#pragma once

class Force
{
public:
   Force(double force);
   double operator/(Mass mass);
#ifndef DEBUG
private:
#endif
   double N;
};
