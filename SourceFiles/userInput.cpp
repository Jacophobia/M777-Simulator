//
// Created by Jacob on 3/16/2022.
//

#include "../HeaderFiles/userInput.h"

UserInput::UserInput(bool left, bool right, bool up, bool down, bool space) :
   left(left), right(right), up(up), down(down), space(space)
{

}

bool UserInput::isLeft()
{
   return false;
}

bool UserInput::isRight()
{
   return false;
}

bool UserInput::isUp()
{
   return false;
}

bool UserInput::isDown()
{
   return false;
}

bool UserInput::isSpace()
{
   return false;
}

bool UserInput::isSpacePressed()
{
   return false;
}
