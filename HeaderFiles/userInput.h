//
// Created by Jacob on 3/16/2022.
//

#ifndef TESTCLASSES_USERINPUT_H
#define TESTCLASSES_USERINPUT_H


class UserInput
{
public:
   UserInput(bool left = 0.0, bool right = 0.0, bool up = 0.0, bool down = 0.0, bool space = 0.0);
   void set(bool left = 0.0, bool right = 0.0, bool up = 0.0, bool down = 0.0, bool space = 0.0);
   bool isLeft();
   bool isRight();
   bool isUp();
   bool isDown();
   bool isSpace();

   bool isLeftPressed();
   bool isRightPressed();
   bool isUpPressed();
   bool isDownPressed();
   bool isSpacePressed();
#ifndef DEBUG
private:
#endif

   bool left;
   bool right;
   bool up;
   bool down;
   bool space;

   bool prevLeft;
   bool prevRight;
   bool prevUp;
   bool prevDown;
   bool prevSpace;
};


#endif //TESTCLASSES_USERINPUT_H
