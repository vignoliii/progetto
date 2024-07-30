#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "b_simulation.hpp"
int main() {
  float sep_param, ali_param, coh_param, sep_distance, near_condition;
  int n_boids;

  // Asks the user to input the parameters and checks if it is positive or
  // negative
  std::cout << "Enter separation parameter (recommended value -1/-1.5): ";
  std::cin >> sep_param;
  while (sep_param > 0) {
    std::cout << "Separation parameter must be negative. Please enter a "
                 "negative value: ";
    std::cin >> sep_param;
  }

  std::cout << "Enter alignment parameter(recommended value 0.1): ";
  std::cin >> ali_param;
  while (ali_param < 0) {
    std::cout << "Alignment parameter must be positive. Please enter a "
                 "positive value: ";
    std::cin >> ali_param;
  }

  std::cout << "Enter cohesion parameter(recommended value 0.007): ";
  std::cin >> coh_param;
  while (coh_param < 0) {
    std::cout << "Cohesion parameter must be positive. Please enter a positive "
                 "value: ";
    std::cin >> coh_param;
  }

  std::cout << "Enter separation distance(recommended value 25): ";
  std::cin >> sep_distance;
  while (sep_distance < 0) {
    std::cout << "Separation distance must be positive. Please enter a "
                 "positive value: ";
    std::cin >> sep_distance;
  }

  std::cout << "Enter near condition(recommended value 70-110): ";
  std::cin >> near_condition;
  while (near_condition < 0) {
    std::cout
        << "Near condition must be positive. Please enter a positive value: ";
    std::cin >> near_condition;
  }
  std::cout << "Enter number of boids (recommended value 100-300): ";
  std::cin >> n_boids;
  while (n_boids < 0) {
    std::cout
        << "Number of boids must be positive. Please enter a positive value: ";
    std::cin >> n_boids;
  }
  Simulation Screen(sep_param, ali_param, coh_param, sep_distance,
                    near_condition);
  Screen.Run_Simulation(n_boids);
  return 0;
}