#include "parallelogram.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cmath>

sukacheva::Parallelogram::Parallelogram(point_t A, point_t B, point_t C) :
  A_(A),
  B_(B),
  C_(C)
{

  if ((A_.x == B_.x == C_.x && A_.y == B_.y == C_.y)
    || !(A_.y == B_.y || B_.y == C_.y))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Parallelogram::getArea() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y) -
    std::min(std::min(A_.y, B_.y), C_.y));
  double lenght = A_.y == B_.y ? std::abs(A_.x - B_.x) : B_.y == C_.y ?
    std::abs(C_.x - B_.x) : std::abs(A_.x - C_.x);
  return height * lenght;
}

sukacheva::rectangle_t sukacheva::Parallelogram::getFrameRect() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y)
    - std::min(std::min(A_.y, B_.y), C_.y));
  double width = std::abs(std::max(std::max(A_.x, B_.x), C_.x) -
    std::min(std::min(A_.x, B_.x), C_.x));
  point_t cos(((std::max(std::max(A_.x, B_.x), C_.x) + std::min(std::min(A_.x, B_.x), C_.x)) * 0.5),
    ((std::max(std::max(A_.y, B_.y), C_.y) + std::min(std::min(A_.y, B_.y), C_.y)) * 0.5));
  return rectangle_t(width, height, cos);
}

void sukacheva::Parallelogram::move(double x, double y) {
  A_ = point_t(A_.x + x, A_.y + y);
  B_ = point_t(B_.x + x, B_.y + y);
  C_ = point_t(C_.x + x, C_.y + y);
}

void sukacheva::Parallelogram::move(point_t center) {
  double newX = center.x;
  double newY = center.y;
  double oldX = (A_.x + B_.x) / 2;
  double oldY = (A_.y + C_.y) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}

void sukacheva::Parallelogram::scale(double k)
{
  double centerX = (A_.x + B_.x) / 2;
  double centerY = (A_.y + C_.y) / 2;
  A_ = point_t((centerX + (A_.x - centerX) * k), (centerY + (A_.y - centerY) * k));
  B_ = point_t((centerX + (B_.x - centerX) * k), (centerY + (B_.y - centerY) * k));
  C_ = point_t((centerX + (C_.x - centerX) * k), (centerY + (C_.y - centerY) * k));
}

void sukacheva::Parallelogram::newScale(point_t center, double k)
{
  double xSideA = A_.x - center.x;
  double ySideA = A_.y - center.y;
  double xSideB = B_.x - center.x;
  double ySideB = B_.y - center.y;
  double xSideC = C_.x - center.x;
  double ySideC = C_.y - center.y;

  A_.x = center.x + xSideA * k;
  A_.y = center.y + ySideA * k;
  B_.x = center.x + xSideB * k;
  B_.y = center.y + ySideB * k;
  C_.x = center.x + xSideC * k;
  C_.y = center.y + ySideC * k;
}
