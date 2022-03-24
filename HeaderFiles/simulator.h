//
// Created by Jacob on 3/16/2022.
//

#ifndef TESTCLASSES_SIMULATOR_H
#define TESTCLASSES_SIMULATOR_H


#include "environment.h"
#include "userInput.h"

class Simulator
{
public:
   Simulator(UserInput * input);
   ~Simulator() { delete input; }
   void setInput(bool left, bool right, bool up, bool down, bool space);
   void update();
   void draw();

#ifndef DEBUG
private:
#endif
   Environment environment;
   UserInput * input;
};


#endif //TESTCLASSES_SIMULATOR_H
