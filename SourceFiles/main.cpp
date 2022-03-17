#ifndef DEBUG
#define DEBUG
#endif

#include <iostream>
//#include "TestFiles/test_Force.h"
#include "../TestFiles/test_Environment.h"
//#include "TestFiles/test_Acceleration.h"
//#include "TestFiles/test_Howitzer.h"
//#include "TestFiles/test_Mass.h"
//#include "TestFiles/test_Seconds.h"
#include "../TestFiles/test_Trajectory.h"
//#include "TestFiles/test_Velocity.h"

int main()
{
   std::cout << "Beginning Test Cases" << std::endl;

   TestEnvironment().run();
//   TestForce().run();
//   TestAcceleration().run();
//   TestMass().run();
//   TestSeconds().run();
   TestTrajectory().run();
//   TestVelocity().run();
//   TestHowitzer().run();

   std::cout << "All Test Cases Completed Successfully" << std::endl;
   return 0;
}
