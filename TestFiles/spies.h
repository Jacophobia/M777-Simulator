//
// Created by Jacob on 3/9/2022.
//

#pragma once

#include "../velocity.h"

class GroundSpy : public Ground
{
public:
   static size_t updateCalls;
   static size_t resetCalls;
   static size_t drawCalls;

   void reset() override
   {
      resetCalls++;
   }
   void update() override
   {
      updateCalls++;
   }
   void draw() override
   {
      drawCalls++;
   }
   static void resetStatistics()
   {
      updateCalls = 0;
      resetCalls = 0;
      drawCalls = 0;
   }

   static size_t numUpdateCalls() { return updateCalls; }
   static size_t numResetCalls()  { return resetCalls;  }
   static size_t numDrawCalls()   { return drawCalls;   }
};

class HowitzerSpy : public Howitzer
{
public:
   static size_t updateCalls;
   static size_t resetCalls;
   static size_t drawCalls;

   void reset() override
   {
      resetCalls++;
   }
   void update() override
   {
      updateCalls++;
   }
   void draw() override
   {
      drawCalls++;
   }
   static void resetStatistics()
   {
      updateCalls = 0;
      resetCalls = 0;
      drawCalls = 0;
   }

   static size_t numUpdateCalls() { return updateCalls; }
   static size_t numResetCalls()  { return resetCalls;  }
   static size_t numDrawCalls()   { return drawCalls;   }
};

class ProjectileSpy : public Projectile
{
public:
   Velocity vel;
   double altitude;
   static size_t updateCalls;
   static size_t resetCalls;
   static size_t drawCalls;
   static size_t velocityCalls;


   void reset() override
   {
      resetCalls++;
   }
   void update() override
   {
      updateCalls++;
   }
   void draw() override
   {
      drawCalls++;
   }
   const Velocity& getVelocity() override
   {
      velocityCalls++;
      return vel;
   }
   static void resetStatistics()
   {
      updateCalls = 0;
      resetCalls = 0;
      drawCalls = 0;
      velocityCalls = 0;
   }


   static size_t numUpdateCalls()    { return updateCalls;    }
   static size_t numResetCalls()     { return resetCalls;     }
   static size_t numDrawCalls()      { return drawCalls;      }
   static size_t numVelocityCalls()  { return velocityCalls;  }

};

size_t GroundSpy::updateCalls;
size_t GroundSpy::resetCalls;
size_t GroundSpy::drawCalls;
size_t HowitzerSpy::updateCalls;
size_t HowitzerSpy::resetCalls;
size_t HowitzerSpy::drawCalls;
size_t ProjectileSpy::updateCalls;
size_t ProjectileSpy::resetCalls;
size_t ProjectileSpy::drawCalls;
size_t ProjectileSpy::velocityCalls;










