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

   virtual const Velocity& getVelocity() const { return vel; }

   virtual double getAltitude() const { return altitude; }

   virtual double getArea() const {return area; }
#ifndef DEBUG
private:
#endif
   double altitude;
   Velocity vel;
   const double area = 0.018842;
};
