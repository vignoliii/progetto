#include <stdlib.h>

#include <iostream>
#include <vector>

#include "vector.hpp"

#ifndef Boid_HPP
#define Boid_HPP
class Boid {
public:
  // Boid properties
  Vector coordinates;
  Vector speed;
  // Constructor
  Boid(float x, float y, float w, float z);

  // Rules
  Vector Alignment(const std::vector<Boid>& ensamble, float near_condition,
                   float ali_param);
  Vector Cohesion(const std::vector<Boid>& ensamble, float near_condition,
                  float coh_param);
  Vector Separation(const std::vector<Boid>& ensamble, float sep_distance,
                    float sep_param);

  // Applies the rules to the boids speed
  void Apply_Rules(const std::vector<Boid>& ensamble, float sep_param,
                   float ali_param, float coh_param, float sep_distance,
                   float near_condition);
  // Applies the rule to the obstacles
  void Apply_Rules_Obs(const std::vector<Boid>& ensamble);
  // Boundary conditions
  void Potential(int window_x, int window_y);
  // Main method to play the simulaiton
  void Play(const std::vector<Boid>& ensamble, float sep_param, float ali_param,
            float coh_param, float sep_distance, float near_condition);
};
#endif