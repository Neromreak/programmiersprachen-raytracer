#include "sphere.hpp"
#include <glm/vec3.hpp>
#include <numbers>
#include <cmath>

// Constructors

Sphere::Sphere()
{}

Sphere::Sphere(glm::vec3 center):
  center_{center}
{}
Sphere::Sphere(glm::vec3 center, float radius):
  center_{center},
  radius_{std::abs(radius)}
{}


// Methods:

float Sphere::area() const
{
  return std::powf(radius_, 2) * std::numbers::pi * 4;
}

float Sphere::volume() const
{
  return std::powf(radius_, 3) * std::numbers::pi * 4.0f / 3.0f;
}


// Sources:
// https://studyflix.de/mathematik/volumen-kugel-2606?timestamp=0