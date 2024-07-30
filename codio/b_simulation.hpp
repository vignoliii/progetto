#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "boid.hpp"
#ifndef B_Simulation_HPP
#define B_Simulation_HPP

class Simulation {
 private:
  sf::RenderWindow window;
  const int window_x = 1280;
  const int window_y = 720;
  const int margin = 30;
  // Parameters of the rules
  const float sep_param;
  const float ali_param;
  const float coh_param;
  const float sep_distance;
  const float near_condition;
  // number of boids

  // Vectors to hold boids, obstacles and their graphical representations
  std::vector<Boid> ensamble;
  std::vector<Boid> Obstacles;
  std::vector<sf::CircleShape> O_triangles;



 public:
  // Constructor
  Simulation(float near_condition, float sep_distance, float sep_param,
             float ali_param, float coh_param);
  // Runs the simulation
  void Run_Simulation(int n_boids);
  // Methods that calculates average distance, speed and their standrd
  // deviations
  float Average_Distance();
  float Average_Speed();
  float Distance_Std(float average_distance);
  float Speed_Std(float average_speed);
  // Prints the results of the functions above
  void Flock_Means();
  // Method for testing
  void Add_Boid(const Boid boid);
};
#endif