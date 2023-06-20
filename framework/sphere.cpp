#include "sphere.hpp"
#include "color.hpp"
#include <numbers>
#include <cmath>
#include "glm/vec3.hpp"
#include <string>

// Constructors
Sphere::Sphere()
{}
Sphere::Sphere(glm::vec3 const& center):
  center_{center}
{}
Sphere::Sphere(glm::vec3 const& center, float radius):
  center_{center},
  radius_{std::abs(radius)}
{}
Sphere::Sphere(std::string const& name, Color const& color):
  Shape::Shape{name, color}
{}
Sphere::Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color):
  Shape::Shape{name, color},
  center_{center},
  radius_{radius}
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