#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public virtual Shape
{
public:
  Rectangle(double lx, double ly, double rx, double ry);
  double getArea();
  rectangle_t getFrameRect();
  void move(double dx, double dy);
  void move(point_t new_center);
  void scale(double n);
private:
  double lp_x;
  double lp_y;
  double rp_x;
  double rp_y;
};

#endif
