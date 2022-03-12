//
// Created by Jacob on 3/9/2022.
//

#pragma once

class Force
{
public:
   Force(double newtons = 0.0) { N = newtons; }
#ifndef DEBUG
private:
#endif
   double N;
};
