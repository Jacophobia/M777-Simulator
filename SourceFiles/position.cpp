/***********************************************************************
 * Source File:
 *    Position : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "../HeaderFiles/position.h"
#include <cassert>

 /******************************************
  * POINT : CONSTRUCTOR WITH X,Y
  * Initialize the point to the passed position
  *****************************************/
Position::Position (double x, double y) : x(0.0), y(0.0)
{
   setX(x);
   setY(y);
}

/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}

