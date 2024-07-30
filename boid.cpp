#include "boid.hpp"

// Constructor that initializes the boid's position and speed
Boid::Boid(float x, float y, float w, float z) {
  coordinates = Vector(x, y);
  speed = Vector(w, z);
};
// Prevents boids from colliding
Vector Boid::Separation(const std::vector<Boid>& ensamble, float sep_distance,
                        float sep_param) {
  Vector V_1{0, 0};

  for (size_t i = 0; i < ensamble.size(); i++) {
    Vector k = ensamble[i].coordinates;
    float dist = coordinates.distance(k);
    if (dist < sep_distance && dist > 0) {
      Vector direction = k.Sub_Vector(coordinates);
      direction.Div_Scalar(dist);
      V_1.Add_Vector(direction);
    }
  }

  if (V_1.magnitude() > 0) {
    V_1.Mul_Scalar(sep_param);
  }

  return V_1;
}
// Makes the near boids go in the same direction
Vector Boid::Alignment(const std::vector<Boid>& ensamble, float near_condition,
                       float ali_param) {
  int n_boids = 0;
  Vector V_2{0, 0};
  for (size_t i = 0; i < ensamble.size(); i++) {
    if (coordinates.distance(ensamble[i].coordinates) < near_condition) {
      Vector k = ensamble[i].speed;

      V_2.Add_Vector(k.Sub_Vector(speed));

      n_boids++;
    }
  }

  if (n_boids > 1) {
    V_2.Div_Scalar(float(n_boids) - 1);
    V_2.Mul_Scalar(ali_param);
  }
  return V_2;
};
// Creates of a flock by keeping near the boids in a certain range of distance
Vector Boid::Cohesion(const std::vector<Boid>& ensamble, float near_condition,
                      float coh_param) {
  int n_boids = 0;
  Vector V_3{0, 0};
  Vector C_mass{0, 0};
  for (size_t i = 0; i < ensamble.size(); i++) {
    Vector k = ensamble[i].coordinates;
    if (coordinates.distance(k) < near_condition &&
        coordinates.distance(k) > 0) {
      C_mass.Add_Vector(k);

      n_boids++;
    }
  }
  if (n_boids > 0) {
    C_mass.Div_Scalar(float(n_boids));
    V_3.Add_Vector(C_mass.Sub_Vector(coordinates));

    V_3.Mul_Scalar(coh_param);
  }
  return V_3;
};
// Adds the velocities returned by the rules to the boids'  speeds. Sets a limit
// to the velocities.
void Boid::Apply_Rules(const std::vector<Boid>& ensamble, float sep_param,
                       float ali_param, float coh_param, float sep_distance,
                       float near_condition) {
  speed.Add3_Vector(Cohesion(ensamble, near_condition, coh_param),
                    Alignment(ensamble, near_condition, ali_param),
                    {Separation(ensamble, sep_distance, sep_param)});

  speed.control();

  coordinates.Add_Vector(speed);
};
// Applies separation to an obstacle so the boids will avoid it.
void Boid::Apply_Rules_Obs(const std::vector<Boid>& ensamble) {
  speed.control();
  coordinates.Add_Vector(Separation(ensamble, 50, -0.6f));
};
// The edges behave like a 1/x potential  in the last 100 pixels of each
// side.
void Boid::Potential(int window_x, int window_y)

{
  float P_force = 40;
  if (coordinates.x != 0 && coordinates.y != 0) {
    if (coordinates.x < 100) {
      speed.x += (P_force / coordinates.distance({0, coordinates.y}));
    }
    if (coordinates.y < 100) {
      speed.y += (P_force / coordinates.distance({coordinates.x, 0}));
    }
    if (coordinates.x > float(window_x) - 100) {
      speed.x -= (P_force / coordinates.distance({1280, coordinates.y}));
    }
    if (coordinates.y > float(window_y) - 100) {
      speed.y -= (P_force / coordinates.distance({coordinates.x, 720}));
    }
  }
};
// Main method to play the simulaiton
void Boid::Play(const std::vector<Boid>& ensamble, float sep_param,
                float ali_param, float coh_param, float sep_distance,
                float near_condition) {
  Apply_Rules(ensamble, sep_param, ali_param, coh_param, sep_distance,
              near_condition);
  Potential(1280, 720);
};
