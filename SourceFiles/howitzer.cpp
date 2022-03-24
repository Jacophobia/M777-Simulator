//
// Created by Jacob on 3/16/2022.
//

#include "../HeaderFiles/howitzer.h"

Howitzer::Howitzer(UserInput * input, const Position& pos) : input(input), pos(pos)
{

}

void Howitzer::update()
{
   if (input->isLeft())
      rotateLeft(0.01);

   if (input->isRight())
      rotateRight(0.01);

   if (barrelAngle > 3 * 3.14 / 2)
      barrelAngle = 3 * 3.14 / 2;

   if (barrelAngle < 3.14 / 2)
      barrelAngle = 3.14 / 2;

   if (input->isSpacePressed())
      fire();
}

void Howitzer::draw()
{

}

void Howitzer::reset() // TODO: find out if we need to pass in a position
{
   barrelAngle = 3.14;
}

void Howitzer::rotateLeft(double angle)
{

}

void Howitzer::rotateRight(double angle)
{

}

// Return the position of the barrel's tip, you'll probs have to do
// some fancy math
Position Howitzer::getTipOfBarrelPos()
{
   return {0.0, 0.0};
}

Trajectory Howitzer::fire()
{
   return Trajectory();
}
