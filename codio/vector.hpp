#include <iostream>
#ifndef Vector_HPP
#define Vector_HPP
class Vector {
 public:
  // Components of a 2-dimensional vector
  float x;
  float y;

  // Default constructor that initializes rhe vector to (0,0)
  Vector();
  // Constructor
  Vector(float a, float b);

  // Define vectors and scalars operations

  Vector Add_Vector(const Vector v_add);
  void Add3_Vector(const Vector v_add1, const Vector v_add2,
                   const Vector v_add3);
  Vector Sub_Vector(const Vector v_sub);
  void Mul_Vector(const Vector v_mul);
  void Div_Vector(const Vector v_div);

  Vector Mul_Scalar(const float param);
  Vector Div_Scalar(const float param);
  // Distance between two points on a 2-dimentional euclidian space
  float distance(const Vector v_2) const;

  // Calculates the magnitude of the current vector
  float magnitude() const;
  // Limits the magnitude of a vector
  void control();
};
#endif