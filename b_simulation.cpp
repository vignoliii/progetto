#include "b_simulation.hpp"

#include <cmath>
#include <iostream>
// Constructor defines the window's properties(window's size, spawn position and
// frame rate) and initializes the simulation with parameters

Simulation::Simulation(float input_sep_param, float input_ali_param,
                       float input_coh_param, float input_sep_distance,
                       float input_near_condition)
    : sep_param(input_sep_param),
      ali_param(input_ali_param),
      coh_param(input_coh_param),
      sep_distance(input_sep_distance),
      near_condition(input_near_condition) {
  window.create(sf::VideoMode(static_cast<unsigned int>(window_x),
                              static_cast<unsigned int>(window_y)),
                "Boids");
  window.setFramerateLimit(60);

  window.setPosition(sf::Vector2i(
      static_cast<int>(sf::VideoMode::getDesktopMode().width / 2 - 400),
      static_cast<int>(sf::VideoMode::getDesktopMode().height / 2 - 320)));
};

void Simulation::Run_Simulation(int n_boids) {
int frame_count=0;
int frames_interval=60;

  sf::Event event;
  std::vector<sf::CircleShape> triangles;
  // Spawns the boids with random positions and speed,
  srand(static_cast<unsigned int>(time(NULL)));
for (int i = 0; i < n_boids; ++i) {
    float Boid_spawn_x = float(rand() % window_x);
    float Boid_spawn_y = float(rand() % window_y);
    float v_spawn_x = float(rand() % 17 - 8);
    float v_spawn_y = float(rand() % 17 - 8);
    sf::CircleShape triangle(5, 3);

    Boid bird(Boid_spawn_x, Boid_spawn_y, v_spawn_x, v_spawn_y);
    triangle.setPosition(Boid_spawn_x, Boid_spawn_y);
    triangle.setFillColor(sf::Color::Red);
    ensamble.push_back(bird);
    triangles.push_back(triangle);
  }
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    // Spawns an obstacle if you press the left mouse button
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      sf::Vector2i Mouse_click = sf::Mouse::getPosition(window);
      if (Mouse_click.x > margin && Mouse_click.x < window_x - margin &&
          Mouse_click.y > margin && Mouse_click.y < window_y - margin) {
        Boid obstacle(float(Mouse_click.x), float(Mouse_click.y), 0, 0);
        sf::CircleShape O_triangle(10, 3);
        O_triangle.setPosition(float(Mouse_click.x), float(Mouse_click.y));
        O_triangle.setFillColor(sf::Color::Green);
        Obstacles.push_back(obstacle);
        O_triangles.push_back(O_triangle);
      }
    }
    window.clear();

    // Draws Obstacles
    for (size_t i = 0; i < O_triangles.size(); i++) {
      window.draw(O_triangles[i]);
    };
    // Draws boids and gives them the rules. Associates the triangles  to the
    // boids

    for (size_t i = 0; i < triangles.size(); i++) {
      ensamble[i].Play(ensamble, sep_param, ali_param, coh_param, sep_distance,
                       near_condition);
      ensamble[i].Apply_Rules_Obs(Obstacles);
      triangles[i].setPosition(ensamble[i].coordinates.x,
                               ensamble[i].coordinates.y);
      window.draw(triangles[i]);
    };

    window.display();
    // Prints the flock's properties every time the counter
    // overcomes frame_interval
  frame_count++;

    if (frame_count >= frames_interval) {
      Flock_Means();

      frame_count = 0;
    }
  }
}
// Calculates the average distance between all pairs of boids in the flock
float Simulation::Average_Distance() {
  float total_distance = 0;
  int count = 0;

  for (size_t i = 0; i < ensamble.size(); i++) {
    for (size_t j = i + 1; j < ensamble.size(); j++) {
      total_distance +=
          ensamble[i].coordinates.distance(ensamble[j].coordinates);
      count++;
    }
  }

  return (count > 0) ? total_distance / static_cast<float>(count) : 0;
}
// Calculates the average speed of all the boids in the flock
float Simulation::Average_Speed() {
  float total_speed = 0;
if (ensamble.size()==0) {return 0;}
  for (const auto& e:ensamble) {
    total_speed += e.speed.magnitude();
  }

  return  total_speed / static_cast<float>(ensamble.size());
             
           
}
// Calculates the standard deviation of distances
float Simulation::Distance_Std(float average_distance) {
  float variance = 0;
  int count = 0;

  for (size_t i = 0; i < ensamble.size(); i++) {
    for (size_t j = i + 1; j < ensamble.size(); j++) {
      float distance =
          ensamble[i].coordinates.distance(ensamble[j].coordinates);
      variance += (distance - average_distance) * (distance - average_distance);
      count++;
    }
  }

  return (count > 1) ? std::sqrt(variance / (static_cast<float>(count) - 1))
                     : 0;
}
// Calculates the standard deviation of speeds
float Simulation::Speed_Std(float average_speed) {
  float variance = 0;

  for (size_t i = 0; i < ensamble.size(); i++) {
    float speed = ensamble[i].speed.magnitude();
    variance += (speed - average_speed) * (speed - average_speed);
  }

  return (ensamble.size() > 1)
             ? std::sqrt(variance / (static_cast<float>(ensamble.size()) - 1))
             : 0;
}
// Prints the averages and their standard deviations
void Simulation::Flock_Means() {
  std::cout << "Average Distance =" << Average_Distance()
            << ", Distance Std Dev = " << Distance_Std(Average_Distance())
            << ", Average Speed = " << Average_Speed()
            << ", Speed Std Dev = " << Speed_Std(Average_Speed()) << std::endl;
}
// Adds a boid to the ensamble vector
void Simulation::Add_Boid(const Boid boid) { ensamble.push_back(boid); }
