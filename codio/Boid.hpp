#include <iostream>
#include "Vector.hpp"
#include <vector>
#include <stdlib.h>

#ifndef Boid_HPP
#define Boid_HPP
class Boid{
    public:
    
Vector coordinates;
Vector speed;

//Costruttore?
Boid(float x,float y,float w,float z);
//Boid();

//Rules
Vector Allignment(const std::vector <Boid> ensamble);    //const fuori??
Vector Cohesion(const std::vector <Boid> ensamble);     //const fuori??
Vector Separation(const std::vector <Boid>& ensamble);   //const fuori??
void Apply_rules(const std::vector <Boid> ensamble )
;
void Pacman_effect(int window_x,
int window_y);
void Potential_Wall(int window_x,int window_y);
void Play(const std::vector <Boid> ensamble);


};
#endif
