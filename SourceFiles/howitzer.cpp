//
// Created by Jacob on 3/16/2022.
//

#include "../HeaderFiles/howitzer.h"
#include "../HeaderFiles/velocity.h"
#include "../HeaderFiles/acceleration.h"
#include "../HeaderFiles/position.h"


Howitzer::Howitzer(UserInput * input, const Position& pos) : input(input), pos(pos)
{

}

void Howitzer::update()
{
   if (input->isLeft())
      rotateLeft(0.01);

   if (input->isRight())
      rotateRight(0.01);

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
   barrelAngle -= angle;

   if (barrelAngle > 3 * 3.14 / 2)
      barrelAngle = 3 * 3.14 / 2;
}

void Howitzer::rotateRight(double angle)
{
   barrelAngle += angle;

   if (barrelAngle < 3.14 / 2)
      barrelAngle = 3.14 / 2;
}

// Return the position of the barrel's tip, you'll probs have to do
// some fancy math
Position Howitzer::getTipOfBarrelPos()
{

   double yPosRelativeToM777 = sin(barrelAngle) * barrelLength;
   double xPosRelativeToM777 = cos(barrelAngle) * barrelLength;
   if (barrelAngle > 3.14 / 2)
   {
      double tipXPos = pos.getX() – xPosRelativeToM777;
         //note the xPos is the M777 position 
   }
   else
   {
      double tipXPos = pos.getX() + xPosRelativeToM777;
         //note the yPos is the M777 position 
   }

   double tipYPos = yPos + M777BaseHeight;
   return { tipXPos, tipYPos };
}

Trajectory Howitzer::fire()
{
   
   return Trajectory(Position(), barrelAngle, Velocity(), Acceleration());
}
