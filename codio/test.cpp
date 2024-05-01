#include<iostream>
#include "B_Simulation.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
int main(){


   /* Simulation Simulazione;
    Simulazione.Run_Simulation();
    return 0;*/
sf::RenderWindow window(sf::VideoMode (1280,720),"Simulation");
window.setFramerateLimit(60);
sf::Event event;
std::vector<sf::CircleShape> triangles;
std::vector<Boid> ensamble;
//while(window.isOpen()){ 

srand(time(NULL));
for(int i=0;i<100;++i){
    float Boid_spawn_x=rand()%1280;
    float Boid_spawn_y=rand()%720;
    sf::CircleShape triangle(10,3);

    Boid bird(Boid_spawn_x,Boid_spawn_y);
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

for (int i = 0; i < triangles.size(); i++) {

    ensamble[i].Play(ensamble);
    triangles[i].setPosition(ensamble[i].coordinates.x, ensamble[i].coordinates.y);
    window.draw(triangles[i]);


};   


window.display();
}
return 0;



/*Vector v1{1,1};
Vector v2{3,4};
Vector v3=v1.Sub_Vector(v2);
std::cout<<v3.x<<v3.y<<std::endl;*/
}
