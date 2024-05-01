#include "Boid.hpp"
Boid::Boid(float x,float y){

    coordinates= Vector(x,y);
    speed=Vector (rand()%3,rand()%3);
};



Vector Boid::Separation(const std::vector <Boid> ensamble){
float sep_distance= 0.0001;//variabile da definire in input
float sep_param= 0.001;   //variabile da definire in input
Vector V_1{0,0};
for (int i=0;i<ensamble.size();i++){
    
    if (coordinates.distance(ensamble[i].coordinates)<sep_distance)
{
    
    Vector rule_1=coordinates.Sub_Vector(ensamble[i].coordinates);
    V_1.Add_Vector(rule_1);

}}
V_1.Mul_Scalar(sep_param);
return V_1;};




Vector Boid::Allignment(const std::vector <Boid> ensamble){
    float near_condition=500.;
float All_param= 1;
int n_boids=0;
Vector V_2{0,0};
for (int i = 0; i <ensamble.size(); i++)
{
        if (coordinates.distance(ensamble[i].coordinates)<near_condition)
{
    
    Vector rule_2=coordinates.Sub_Vector(ensamble[i].coordinates);
    V_2.Add_Vector(rule_2);
   

n_boids++;
}

}
V_2.Mul_Scalar(All_param);
V_2.Div_Scalar(n_boids-1);
return V_2;
};    



Vector Boid::Cohesion(const std::vector <Boid> ensamble){
float near_condition= 1;
float coh_param= 0.001;
int n_boids=0;
Vector V_3{0,0};
Vector C_mass{0,0};
for (int i=0;i<ensamble.size();i++){
    
    if (coordinates.distance(ensamble[i].coordinates)<near_condition)
{C_mass.Add_Vector(ensamble[i].coordinates);
    n_boids++;
    }
} 
C_mass.Div_Scalar(n_boids-1);

Vector rule_3= C_mass.Sub_Vector(coordinates);
V_3.Add_Vector(C_mass);
V_3.Mul_Scalar(coh_param);
return V_3;
 };     

void Boid::Apply_rules(const std::vector <Boid> ensamble ){
    //speed.Add3_Vector(Allignment(ensamble),Separation(ensamble),Cohesion(ensamble));
    speed.Add_Vector(Cohesion(ensamble));
   // speed.control();
    coordinates.Add_Vector(speed);
};
;
void Boid::Pacman_effect(int window_x,
int window_y){
    if (coordinates.x<0){coordinates.x=window_x;}
    if (coordinates.y<0){coordinates.y=window_y;}
    if (coordinates.x>window_x){coordinates.x=1;}
    if (coordinates.y>window_y){coordinates.y=1;}

};

void Boid::Play(const std::vector <Boid> ensamble)
{
 Apply_rules(ensamble);
 Pacman_effect(1280,700);

};

//effetto pacman, prima sfml definire finestra ecc...
