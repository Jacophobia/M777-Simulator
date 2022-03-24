//
// Created by Jacob on 3/16/2022.
//

#include "../HeaderFiles/userInput.h"

UserInput::UserInput(bool left, bool right, bool up, bool down, bool space) :
   left(left), right(right), up(up), down(down), space(space){}

bool UserInput::isLeft()
{
   return left;
}

bool UserInput::isRight()
{
   return right;
}

bool UserInput::isUp()
{
   return up;
}

bool UserInput::isDown()
{
   return down;
}

bool UserInput::isSpace()
{
   return space;
}

bool UserInput::isSpacePressed()
{
   return !prevSpace && space;
}
