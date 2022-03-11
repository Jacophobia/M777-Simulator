//
// Created by Jacob on 3/9/2022.
//

#pragma once

class Ground
{
public:
   Ground() = default;

   virtual void update() {}

   virtual void draw() {}

   virtual void reset() {}
#ifndef DEBUG
private:
#endif

};
