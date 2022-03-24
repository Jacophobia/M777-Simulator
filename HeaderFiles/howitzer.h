//
// Created by Jacob on 3/9/2022.
//

#pragma once

#include "userInput.h"
#include "position.h"
#include "trajectory.h"

class Howitzer
{
public:
   Howitzer(UserInput * input, const Position& pos = Position(0.0, 0.0));

   void update();
   void draw();
   void reset();
   Trajectory fire();
   // TODO: maybe return less
   Position getTarget();
   void setPos(Position pos);


#ifndef DEBUG
private:
#endif
   void rotateLeft(double angle);
   void rotateRight(double angle);
   Position getTipOfBarrelPos();

   UserInput * input;
   Position pos;
   double barrelAngle;
   double barrelLength;
   // TODO: if feeling adventurous, figure out how to get angle and
   //  length of barrel based on pos and tipPos
};
