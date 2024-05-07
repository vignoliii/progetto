#include <iostream>
#include "B_Simulation.hpp"

Simulation::Simulation(){
 window.create(sf::VideoMode(window_x, window_y), "Boids");
window.setFramerateLimit(60);
};




void Simulation:: New_Boid(const Boid boid){ensamble.push_back(boid);};
void Simulation::Run_Simulation(){


   /* Simulation Simulazione;
    Simulazione.Run_Simulation();
    return 0;*/
sf::Event event;
//while(window.isOpen()){ 

srand(time(NULL));
for(int i=0;i<200;++i){
    float Boid_spawn_x=rand()%window_x;
    float Boid_spawn_y=rand()%window_y;
    float v_spawn_x=rand()%17 -8;
    float v_spawn_y=rand()%17 -8;
    sf::CircleShape triangle(5,3);

    Boid bird(Boid_spawn_x,Boid_spawn_y,v_spawn_x, v_spawn_y);
    triangle.setPosition(Boid_spawn_x,Boid_spawn_y);
    triangle.setFillColor(sf::Color::Red);
    ensamble.push_back(bird);
    triangles.push_back(triangle);


}
//for (int i = 0; i < ensamble.size(); i++)
     //{ ensamble[i].Play(ensamble);}
while(window.isOpen()){ 
while(window.pollEvent(event)){
if (event.type==sf::Event::Closed){window.close();};}


window.clear();
Vector z={0,0};
for (int i = 0; i < triangles.size(); i++) {

    ensamble[i].Play(ensamble);
    triangles[i].setPosition(ensamble[i].coordinates.x, ensamble[i].coordinates.y);
    window.draw(triangles[i]); 
 z.Add_Module(ensamble[i].speed);


//std::cout<<ensamble[i].speed.x<<ensamble[i].speed.y<<std::endl;
//std::cout<<triangles.size();
//std::cout<<ensamble.size();
};   
std::cout<<(z.x/ensamble.size())<<' '<<(z.y/ensamble.size())<<std::endl;

window.display();
}  

}
