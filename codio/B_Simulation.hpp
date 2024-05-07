#include <iostream>
#include "Boid.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#ifndef B_Simulation_HPP
#define B_Simulation_HPP

class Simulation{public:
Simulation();
int window_x=1280;
int window_y=720;
std::vector <Boid> ensamble;
std::vector <sf::CircleShape> triangles;
sf::RenderWindow window;
    void Run_Simulation()
    ;

    void New_Boid(const Boid boid);
    void Draw();
   
}
;
#endif
