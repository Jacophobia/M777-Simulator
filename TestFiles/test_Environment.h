﻿#pragma once

#include "../HeaderFiles/environment.h"
#include <cassert>
#include <cmath>
#include "../HeaderFiles/velocity.h"
#include "../HeaderFiles/acceleration.h"

class TestEnvironment
{
public:
   void run()
   {
      getLinearInterpolation_testX1LowerThanX2();
      getLinearInterpolation_testX1EqualToX2();
      getLinearInterpolation_testX1GreaterThanX2();
      getLinearInterpolation_testX3BeforeX1OrX2();
      getLinearInterpolation_testX3AfterX1OrX2();
      getLinearInterpolation_testX3EqualsX1();
      getLinearInterpolation_testX3EqualsX2();


      getSpeedOfSound_testAltitudeIsZero();
      getSpeedOfSound_testAltitudeIs1000();
      getSpeedOfSound_testAltitudeIs40000();
      getSpeedOfSound_testAltitudeIsGreaterThan40000();
      getSpeedOfSound_testAltitudeIs1500();
      getSpeedOfSound_testAltitudeIs35000();


      getGravitationalAcceleration_testAltitudeIsZero();
      getGravitationalAcceleration_testAltitudeIsNeg();
      getGravitationalAcceleration_testAltitudeIs1000();
      getGravitationalAcceleration_testAltitudeIs25000();
      getGravitationalAcceleration_testAltitudeIsGreaterThan25000();
      getGravitationalAcceleration_testAltitudeIs1500();
      getGravitationalAcceleration_testAltitudeIs22500();


      getAirDensity_testAltitudeIsZero();
      getAirDensity_testAltitudeIsNeg();
      getAirDensity_testAltitudeIs1000();
      getAirDensity_testAltitudeIs80000();
      getAirDensity_testAltitudeIsGreaterThan80000();
      getAirDensity_testAltitudeIs1500();
      getAirDensity_testAltitudeIs75000();


      getDragCoefficient_testMachIsPoint3();
      getDragCoefficient_testMachIsLessThanPoint3();
      getDragCoefficient_testMachIsNeg();
      getDragCoefficient_testMachIsPoint5();
      getDragCoefficient_testMachIs5();
      getDragCoefficient_testMachIsGreaterThan5();
      getDragCoefficient_testMachIsPoint4();
      getDragCoefficient_testMachIs3Point940();

      getForceOfAirResistance_testPosVelocityPosAltitude();
      getForceOfAirResistance_testZeroVelocityPosAltitude();
      getForceOfAirResistance_testNegVelocityPosAltitude();
      getForceOfAirResistance_testPosVelocZeroAltitude();
      getForceOfAirResistance_testZeroVelocityZeroAltitude();
      getForceOfAirResistance_testNegVelocityZeroAltitude();
      getForceOfAirResistance_testPosVelocityNegAltitude();
      getForceOfAirResistance_testZeroVelocityNegAltitude();
      getForceOfAirResistance_testNegVelocityNegAltitude();
      getForceOfAirResistance_testSuperHighVelocity();


      getMach_testVelocityIsNeg();
      getMach_testVelocityIsPos();
      getMach_testVelocityIsZero();


//      update_testProjectileFired();
//      update_testProjectileUnfired();
//
//
//      reset_test();
//
//
//      draw_test();
   }
private:
   static bool aboutEquals(double val1, double val2)
   {
      if(abs(val1 - val2) < 0.001)
      {
         return true;
      }
      else
      {
         std::cout << val1 << " != " << val2 << std::endl;
         return false;
      }
   }

   static bool isEqual(double val1, double val2)
   {
      if (val1 == val2)
      {
         return true;
      }
      else
      {
         std::cout << val1 << " != " << val2 << std::endl;
         return false;
      }
   }

   // x1, y1, x2, y2, x3
   // x1 is lower than x2
   static void getLinearInterpolation_testX1LowerThanX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 0;
      double r0 = 1.225;
      double d1 = 1000;
      double r1 = 1.112;
      double d = 200;
      // exercise
      double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
      // verify
      assert(aboutEquals(result, 1.2024));
      delete input;
   }  // teardown

   // x1 is equal to x2
   static void getLinearInterpolation_testX1EqualToX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 0;
      double r0 = 1.225;
      double d1 = 0;
      double r1 = 1.225;
      double d = 200;
      // exercise
      double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
      // verify
      assert(aboutEquals(result, 1.225));
      delete input;
   }  // teardown

   // x1 is greater than x2
   static void getLinearInterpolation_testX1GreaterThanX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 1000;
      double r0 = 1.112;
      double d1 = 0;
      double r1 = 1.225;
      double d = 200;
      // exercise
      double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
      // verify
      assert(aboutEquals(result, 1.2024));
      delete input;
   }  // teardown

   // x3 is before x1 and x2
   static void getLinearInterpolation_testX3BeforeX1OrX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 200;
      double r0 = 1.2024;
      double d1 = 1000;
      double r1 = 1.112;
      double d = 0;
      // exercise
      try
      {
         double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
         // verify
         assert(false);
      }
      catch(...) {}
      delete input;
   }  // teardown

   // x3 is after x1 and x2
   static void getLinearInterpolation_testX3AfterX1OrX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 0;
      double r0 = 1.225;
      double d1 = 200;
      double r1 = 1.2024;
      double d = 1000;
      // exercise
      try
      {
         double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
         // verify
         assert(false);
      }
      catch(...) {}
      delete input;
   }  // teardown

   // x3 is equal to x1
   static void getLinearInterpolation_testX3EqualsX1()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 0.0;
      double r0 = 1.225;
      double d1 = 1000;
      double r1 = 1.112;
      double d = 0.0;
      // exercise
      double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
      // verify
      assert(aboutEquals(result, 1.225));
      delete input;
   }  // teardown

   // x3 is equal to x2
   static void getLinearInterpolation_testX3EqualsX2()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double d0 = 0.0;
      double r0 = 1.225;
      double d1 = 1000;
      double r1 = 1.112;
      double d = 1000.0;
      // exercise
      double result = env.getLinearInterpolation(d0, r0, d1, r1, d);
      // verify
      assert(aboutEquals(result, 1.112));
      delete input;
   }  // teardown


   static void getSpeedOfSound_testAltitudeIsZero()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 0.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 340.0));
      delete input;
   }  // teardown

   void getSpeedOfSound_testAltitudeIs1000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1000.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 336.0));
      delete input;
   }  // teardown

   void getSpeedOfSound_testAltitudeIs40000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 40000.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 324.0));
      delete input;
   }  // teardown
   void getSpeedOfSound_testAltitudeIsGreaterThan40000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 40001.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 324.0));
      delete input;
   }  // teardown
   void getSpeedOfSound_testAltitudeIs1500()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1500.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 334.0));
      delete input;
   }  // teardown
   void getSpeedOfSound_testAltitudeIs35000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 3500.0;
      // exercise
      double result = env.getSpeedOfSound(altitude);
      // verify
      assert(isEqual(result, 326.0));
      delete input;
   }  // teardown


   // get gravitational acceleration

   void getGravitationalAcceleration_testAltitudeIsZero()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 0.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.807));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIsNeg()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = -1.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.807));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIs1000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1000.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.804));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIs25000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 25000.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.730));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIsGreaterThan25000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 25000.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.730));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIs1500()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1500.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.8025));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown

   void getGravitationalAcceleration_testAltitudeIs22500()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 22500.0;
      // exercise
      Acceleration result = env.getGravitationalAcceleration(altitude);
      // verify
      assert(isEqual(result.ddy, -9.7375));
      assert(isEqual(result.ddx, 0.0));
      delete input;
   }  // teardown




   // get air density

   void getAirDensity_testAltitudeIsZero()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 0.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(result == 1.2250);
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIsNeg()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = -1.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(result == 1.2250);
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIs1000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1000.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(result == 1.112);
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIs80000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 80000.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(result == 0.0000185);
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIsGreaterThan80000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 80001.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(isEqual(result, 0.0000185));
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIs1500()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 1500.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(aboutEquals(result, 1.0595));
      delete input;
   }  // teardown

   void getAirDensity_testAltitudeIs75000()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double altitude = 75000.0;
      // exercise
      double result = env.getAirDensity(altitude);
      // verify
      assert(result == .00005065);
      delete input;
   }  // teardown



   void getDragCoefficient_testMachIsPoint3()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = .300;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(isEqual(result, .1629));
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIsLessThanPoint3()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = .200;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .1629);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIsNeg()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = -.300;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .1629);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIsPoint5()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = .500;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .1659);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIs5()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = 5.0;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .2656);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIsGreaterThan5()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = 5.1;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .2656);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIsPoint4()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = .4;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(result == .1644);
      delete input;
   }  // teardown

   void getDragCoefficient_testMachIs3Point940()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      double mach = .940;
      // exercise
      double result = env.getDragCoefficient(mach);
      // verify
      assert(aboutEquals(result, .31485));
      delete input;
   }  // teardown




   void getForceOfAirResistance_testPosVelocityPosAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 336.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 1000.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(aboutEquals(drag.N, 503.600326)); // 0.5 * 0.4258 * 1.1120000 * (336 * 336) * 0.018842
      delete input;
   }  // teardown
   void getForceOfAirResistance_testZeroVelocityPosAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 0.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 1000.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(drag.N == 0.0);
      delete input;
   }  // teardown
   void getForceOfAirResistance_testNegVelocityPosAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = -336.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 1000.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(aboutEquals(drag.N, 503.600326));  // 0.5 * 0.4258 * 1.1120000 * (-336 * -336) * 0.018842
      delete input;
   }  // teardown
   void getForceOfAirResistance_testPosVelocZeroAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 340.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 0.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(aboutEquals(drag.N, 568.063105));  // 0.5 * 0.4258 * 1.2250000 * (340 * 340) * 0.018842
      delete input;
   }  // teardown
   void getForceOfAirResistance_testZeroVelocityZeroAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 0.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 0.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(isEqual(drag.N, 0));
      delete input;
   }  // teardown
   void getForceOfAirResistance_testNegVelocityZeroAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = -340.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 0.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(aboutEquals(drag.N, 568.063105));  // 0.5 * 0.4258 * 1.2250000 * (-340 * -340) * 0.018842
      delete input;
   }  // teardown
   void getForceOfAirResistance_testPosVelocityNegAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 340.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = -1.0;
      // exercise
      try {
         Force drag = env.getAirResistance();
         // verify
         assert(false);
      }
      catch (...) {}
      delete input;
   }  // teardown
   void getForceOfAirResistance_testZeroVelocityNegAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 0.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = -1.0;
      // exercise
      try {
         Force drag = env.getAirResistance();
         // verify
         assert(false);
      }
      catch (...) {}
      delete input;
   }  // teardown
   void getForceOfAirResistance_testNegVelocityNegAltitude()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = -340.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = -1.0;
      // exercise
      try {
         Force drag = env.getAirResistance();
         // verify
         assert(false);
      }
      catch (...) {}
      delete input;
   }  // teardown
   void getForceOfAirResistance_testSuperHighVelocity()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 100000000.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 0.0;
      // exercise
      Force drag = env.getAirResistance();
      // verify
      assert(aboutEquals(drag.N, 30652165600000.008));  // 0.5 * 0.2656 * 1.2250000 * (100000000.0 * 100000000.0) * 0.018842
      delete input;
   }  // teardown


   void getMach_testVelocityIsNeg()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = -340.0;
      env.proj.vel.dy = 0.0;
      env.proj.altitude = 0.0;
      // exercise
      double mach = env.getMach();
      // verify
      assert(mach == 1.0);
      delete input;
   }  // teardown
   void getMach_testVelocityIsPos()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 340.0;
      env.proj.vel.dy = 0.0;
      // exercise
      double mach = env.getMach();
      // verify
      assert(mach == 1.0);
      delete input;
   }  // teardown
   void getMach_testVelocityIsZero()
   {
      // setup
      UserInput * input = new UserInput();
      Environment env(input);
      env.isProjFired = true;
      env.proj.vel.dx = 0;
      env.proj.vel.dy = 0;
      // exercise
      double mach = env.getMach();
      // verify
      assert(mach == 0);
      delete input;
   }  // teardown


//   void update_testProjectileFired()
//   {
//      // setup
//      Environment env;
//      env.proj = Projectile();
//      env.howitzer = Howitzer();
//      env.ground = Ground();
//      Howitzer::resetStatistics();
//      Ground::resetStatistics();
//      Projectile::resetStatistics();
//
//      env.isProjFired = true;
//      // exercise
//      env.update();
//      // verify
//      assert(Howitzer::numDrawCalls() == 0);
//      assert(Ground::numDrawCalls() == 0);
//      assert(Projectile::numDrawCalls() == 0);
//      assert(Howitzer::numResetCalls() == 0);
//      assert(Ground::numResetCalls() == 0);
//      assert(Projectile::numResetCalls() == 0);
//      assert(Howitzer::numUpdateCalls() == 1);
//      assert(Ground::numUpdateCalls() == 1);
//      assert(Projectile::numUpdateCalls() == 1);
//   }  // teardown
//
//   void update_testProjectileUnfired()
//   {
//      // setup
//      Environment env;
//      env.proj = Projectile();
//      env.howitzer = Howitzer();
//      env.ground = Ground();
//      Howitzer::resetStatistics();
//      Ground::resetStatistics();
//      Projectile::resetStatistics();
//
//      env.isProjFired = false;
//      // exercise
//      env.update();
//      // verify
//      assert(Howitzer::numDrawCalls() == 0);
//      assert(Ground::numDrawCalls() == 0);
//      assert(Projectile::numDrawCalls() == 0);
//      assert(Howitzer::numResetCalls() == 0);
//      assert(Ground::numResetCalls() == 0);
//      assert(Projectile::numResetCalls() == 0);
//      assert(Howitzer::numUpdateCalls() == 1);
//      assert(Ground::numUpdateCalls() == 1);
//      assert(Projectile::numUpdateCalls() == 0);
//   }  // teardown
//
//
//   void reset_test()
//   {
//      // setup
//      Environment env;
//      env.proj = Projectile();
//      env.howitzer = Howitzer();
//      env.ground = Ground();
//      Howitzer::resetStatistics();
//      Ground::resetStatistics();
//      Projectile::resetStatistics();
//      // exercise
//      env.reset();
//      // verify
//      assert(Howitzer::numDrawCalls() == 0);
//      assert(Ground::numDrawCalls() == 0);
//      assert(Projectile::numDrawCalls() == 0);
//      assert(Howitzer::numResetCalls() == 1);
//      assert(Ground::numResetCalls() == 1);
//      assert(Projectile::numResetCalls() == 1);
//      assert(Howitzer::numUpdateCalls() == 0);
//      assert(Ground::numUpdateCalls() == 0);
//      assert(Projectile::numUpdateCalls() == 0);
//   }  // teardown
//
//
//   void draw_test()
//   {
//      // setup
//      Environment env;
//      env.proj = Projectile();
//      env.howitzer = Howitzer();
//      env.ground = Ground();
//      Howitzer::resetStatistics();
//      Ground::resetStatistics();
//      Projectile::resetStatistics();
//      // exercise
//      env.draw();
//      // verify
//      assert(Howitzer::numDrawCalls() == 1);
//      assert(Ground::numDrawCalls() == 1);
//      assert(Projectile::numDrawCalls() == 1);
//      assert(Howitzer::numResetCalls() == 0);
//      assert(Ground::numResetCalls() == 0);
//      assert(Projectile::numResetCalls() == 0);
//      assert(Howitzer::numUpdateCalls() == 0);
//      assert(Ground::numUpdateCalls() == 0);
//      assert(Projectile::numUpdateCalls() == 0);
//   }  // teardown
};