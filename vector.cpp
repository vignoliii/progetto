#include "vector.hpp"

#include <math.h>
// Default constructor that initializes rhe vector to (0,0)
Vector::Vector() {
  x = 0;
  y = 0;
}
// Constructor
Vector::Vector(float a, float b) {
  x = a;
  y = b;
}
// Operations between vectors
// Adds a vector to the current one
Vector Vector::Add_Vector(const Vector v_add) {
  x += v_add.x;
  y += v_add.y;
  return {x, y};
};
// Adds 3 vectors to the current one
void Vector::Add3_Vector(const Vector v_add1, const Vector v_add2,
                         const Vector v_add3) {
  x += v_add1.x + v_add2.x + v_add3.x;
  y += v_add1.y + v_add2.y + v_add3.y;
};
// Subtracts a vector to the current one
Vector Vector::Sub_Vector(const Vector v_sub) {
  x -= v_sub.x;
  y -= v_sub.y;
  return {x, y};
};
// Multiplies a vector by the current one
void Vector::Mul_Vector(const Vector v_mul) {
  x *= v_mul.x;
  y *= v_mul.y;
};
// Divides the current vector by another one
void Vector::Div_Vector(const Vector v_div) {
  x /= v_div.x;
  y /= v_div.y;
};
// Scalars and vectors operations
// Multiplies a vector by a scalar
Vector Vector::Mul_Scalar(const float param) {
  x *= param;
  y *= param;
  return {x, y};
};
// Divides a vector by a scalar
Vector Vector::Div_Scalar(const float param) {
  x /= param;
  y /= param;
  return {x, y};
};
// Calculates the distance between two points on a 2-dimentional euclidian space
float Vector::distance(const Vector v_2) const {
  float d_x = x - v_2.x;

  float d_y = y - v_2.y;

  return sqrt((d_x * d_x) + (d_y * d_y));
};

float Vector::magnitude() const {
  float mag2 = x * x + y * y;
  return sqrt(mag2);
};
// Sets a limit to the vector magnitude
void Vector::control() {
  float maxspeed = 4;
  if (magnitude() > maxspeed) {
    x = (x / magnitude()) * maxspeed;
    y = (y / (magnitude() + 0.2f)) * maxspeed;
  }
};
