#include <iostream>
#ifndef Vector_HPP
#define Vector_HPP
class Vector{
public:
float x;
float y;


// dove definisco i costruttori????
Vector(){x=0;
y=0;}

Vector(float x, float y)
{
this->x=x;
this->y=y;

}

//Define vectors and scalars operations


Vector Add_Vector(const Vector v_add);
void Add3_Vector(const Vector v_add1 ,const Vector v_add2,const Vector v_add3);
Vector Sub_Vector(const Vector v_sub);
void Mul_Vector(const Vector v_mul);
void Div_Vector(const Vector v_div);


Vector Mul_Scalar(const float param);
Vector Div_Scalar(const float param);

double distance(const Vector v_2);
double magnitude();
void control();
Vector Add_Module(const Vector v_add);

};
#endif
