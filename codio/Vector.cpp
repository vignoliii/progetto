#include <math.h>
#include "Vector.hpp"





Vector Vector::Add_Vector(const Vector v_add){
 x+=v_add.x ;
 y+=v_add.y;
return{x,y};
};

void Vector::Add3_Vector(const Vector v_add1 ,const Vector v_add2,const Vector v_add3){
 x+=v_add1.x+v_add2.x+v_add3.x;
 y+=v_add1.y+v_add2.y+v_add3.y;

  
};





Vector Vector::Sub_Vector(const Vector v_sub)
{ x-=v_sub.x ;
 y-=v_sub.y;
 return{x,y};
 };

void Vector::Mul_Vector(const Vector v_mul){
    x*=v_mul.x;
    y*=v_mul.y;

};
void Vector::Div_Vector(const Vector v_div){
    x/=v_div.x;
    y/=v_div.y;
};


Vector Vector::Mul_Scalar(const float param){
    x*=param;
    y*=param;
return{x,y};
};
Vector Vector::Div_Scalar(const float param){
    x/=param;
    y/=param;
return{x,y};
};


double Vector::distance(const Vector v_2){
double d_x= x-v_2.x;

double d_y= y-v_2.y;

return sqrt(d_x*d_x+d_y*d_y);


};  
double Vector::magnitude(){
double mag2=x*x+y*y;
return sqrt(mag2);

};

void Vector::control(){
if (x>5)
{x-=1;}
if (x<-5)
{x+=1;}

if (y>5)
{y-=1;}
if (y<-5)
{y+=1;}

};
