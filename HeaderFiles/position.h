/***********************************************************************
 * Header File:
 *    Position : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>

 /*********************************************
  * POINT
  * A single position.
  *********************************************/
class Position
{
public:
   // constructors
   Position() : x(0.0), y(0.0) {}
   Position(double x, double y);
   Position(const Position& pt) : x(pt.x), y(pt.y) {}

   // getters
   double getX()       const { return x; }
   double getY()       const { return y; }
   bool operator == (const Position& rhs) const
   {
      return x == rhs.x && y == rhs.y;
   }
   bool operator != (const Position& rhs) const
   {
      return x != rhs.x || y != rhs.y;
   }

   // setters
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }
   void addX(double dx) { setX(getX() + dx); }
   void addY(double dy) { setY(getY() + dy); }
   Position& operator = (const Position& rhs)
   {
      x = rhs.x;
      y = rhs.y;
      return *this;
   }
#ifndef DEBUG
private:
#endif
   double x;           // horizontal position
   double y;           // vertical position
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);

