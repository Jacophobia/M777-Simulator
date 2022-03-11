//
// Created by Jacob on 3/9/2022.
//

#pragma once

class Projectile
{
public:
   virtual void update() {}

   virtual void draw() {}

   virtual void reset() {}

   virtual const Velocity& getVelocity() { return vel; }
#ifndef DEBUG
private:
#endif
   double altitude;
   Velocity vel;
};
