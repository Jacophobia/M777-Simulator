//
// Created by Jacob on 3/9/2022.
//
#pragma once

#include "acceleration.h"
#include "mass.h"


class Force
{
public:
   Force(double newtons = 0.0);
//   double operator/(Mass mass) const;
#ifndef DEBUG
private:
#endif
   double N;
};
