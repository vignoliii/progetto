#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "b_simulation.hpp"
#include "boid.hpp"
#include "doctest.h"
#include "vector.hpp"
// Testing Vector's functions

TEST_CASE("Testing Constructors") {
  Vector v_1;
  Vector v_2(2.1f, 3.2f);
  CHECK(v_1.x == 0);
  CHECK(v_1.y == 0);
  CHECK(v_2.x == 2.1f);
  CHECK(v_2.y == 3.2f);
}

TEST_CASE("Testing Add_Vector") {
  Vector v_1(1.0f, 2.0f);
  Vector v_2(3.0f, 4.0f);
  Vector sum = v_1.Add_Vector(v_2);

  CHECK(sum.x == 4.0f);
  CHECK(sum.y == 6.0f);
}
TEST_CASE("Testing Mul_Scal") {
  Vector v_1(4.0f, 0);
  CHECK(v_1.Mul_Scalar(1.2).x == 4.8f);
  CHECK(v_1.Mul_Scalar(1.2).y == 0);
}

TEST_CASE("Testing distance") {
  Vector v_1(4.0f, 0);
  Vector v_2(3, 3);
  Vector v_3(1, 5);
  CHECK(v_1.distance(v_2) == doctest::Approx(3.162).epsilon(0.001));
  CHECK(v_1.distance(v_3) == v_3.distance(v_1));
  CHECK(v_3.distance(v_2) == doctest::Approx(2.828).epsilon(0.001));
}

TEST_CASE("Testing magnitude") {
  Vector v_1(1.0f, 2.0f);
  Vector v_2(3.0f, 4.0f);
  CHECK(v_1.magnitude() == doctest::Approx(2.236).epsilon(0.001));
  CHECK(v_2.magnitude() == 5.0f);
}

TEST_CASE("Testing control") {
  Vector v_1(1.0f, 2.0f);
  Vector v_2(3.0f, 4.0f);
  v_1.control();
  v_2.control();
  CHECK(v_1.x == 1.0f);
  CHECK(v_1.y == 2.0f);
  CHECK(v_2.magnitude() < 5.0f);
}

// Testing Boid's functions
TEST_CASE("Testing the constructor") {
  Boid b(10.0f, 7.3f, 1.0f, 0);

  CHECK(b.coordinates.x == 10);
  CHECK(b.coordinates.y == 7.3f);
  CHECK(b.speed.x == 1);
  CHECK(b.speed.y == 0);
}

TEST_CASE("Testing Separation") {
  Boid b_1(0, 0, 0, 0);
  Boid b_2(1, 1, 0, 0);
  Boid b_3(40, 40, 0, 0);

  std::vector<Boid> boids_1 = {b_1, b_2};
  std::vector<Boid> boids_2 = {b_1, b_3};

  Vector sep_1 = b_1.Separation(boids_1, 25.0f, -1.0f);
  Vector sep_2 = b_1.Separation(boids_2, 25.0f, -1.0f);
  CHECK(sep_1.x != 0);
  CHECK(sep_1.y != 0);
  CHECK(sep_2.x == 0);
  CHECK(sep_2.y == 0);
}
TEST_CASE("Testing Cohesion") {
  Boid b_1(0, 0, 0, 0);
  Boid b_2(1, 1, 0, 0);
  Boid b_3(40, 40, 0, 0);

  std::vector<Boid> boids_1 = {b_1, b_2};
  std::vector<Boid> boids_2 = {b_1, b_3};

  Vector coh_1 = b_1.Cohesion(boids_1, 25, 0.007f);
  Vector coh_2 = b_1.Cohesion(boids_2, 25, 0.007f);
  CHECK(coh_1.x != 0);
  CHECK(coh_1.y != 0);
  CHECK(coh_2.x == 0);
  CHECK(coh_2.y == 0);
}
TEST_CASE("Testing Alignment") {
  Boid b_1(0, 0, 1, 1);
  Boid b_2(1, 1, 0, 0);
  Boid b_3(40, 40, 1, 1);

  std::vector<Boid> boids_1 = {b_1, b_2};
  std::vector<Boid> boids_2 = {b_1, b_3};

  Vector ali_1 = b_1.Alignment(boids_1, 25, 0.1f);
  Vector ali_2 = b_1.Alignment(boids_2, 25, 0.1f);
  CHECK(ali_1.x != 0);
  CHECK(ali_1.y != 0);
  CHECK(ali_2.x == 0);
  CHECK(ali_2.y == 0);
}

// Testing B_Simulation's functions
Simulation s(1, 2, 3, 4, 5);
TEST_CASE("Testing average distance and speed") {
  Boid b_1(0, 0, 0, 0);
  Boid b_2(1, 1, 1, 1);
  Boid b_3(2, 3, 2, 3);
  s.Add_Boid(b_1);
  CHECK(s.Average_Distance() == 0);
  CHECK(s.Average_Speed() == b_1.speed.magnitude());
  s.Add_Boid(b_2);
  s.Add_Boid(b_3);
  CHECK(s.Average_Distance() == doctest::Approx(2.418).epsilon(0.001));
  CHECK(s.Average_Speed() == doctest::Approx(1.673).epsilon(0.001));
}

TEST_CASE("Testing StDs") {
  CHECK(s.Distance_Std(2.419) == doctest::Approx(1.109).epsilon(0.001));
  CHECK(s.Speed_Std(1.673) == doctest::Approx(1.817).epsilon(0.001));
}