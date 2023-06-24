#include "sphere.hpp"
#include "color.hpp"
#include <numbers>
#include <cmath>
#include "glm/vec3.hpp"
#include "glm/gtx/intersect.hpp"
#include <string>
#include "ray.hpp"
#include "hit_point.hpp"

// Constructors:
Sphere::Sphere():
  Shape::Shape{}
{ std::cout << "Sphere constructor\n"; }
Sphere::Sphere(glm::vec3 const& center):
  Shape::Shape{},
  center_{center}
{ std::cout << "Sphere constructor\n"; }

Sphere::Sphere(glm::vec3 const& center, float radius):
  Shape::Shape{},
  center_{center},
  radius_{std::abs(radius)}
{ std::cout << "Sphere constructor\n"; }

Sphere::Sphere(std::string const& name, Color const& color):
  Shape::Shape{name, color}
{ std::cout << "Sphere constructor\n"; }

Sphere::Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color):
  Shape::Shape{name, color},
  center_{center},
  radius_{radius}
{ std::cout << "Sphere constructor\n"; }

Sphere::~Sphere()
{ std::cout << "Sphere destructor\n"; }


// virtual Methods:
float Sphere::area() const
{
  return std::powf(radius_, 2) * std::numbers::pi * 4;
}

float Sphere::volume() const
{
  return std::powf(radius_, 3) * std::numbers::pi * 4.0f / 3.0f;
}

std::ostream& Sphere::print(std::ostream& os) const
{
  Shape::print(os);
  os << ", Center: " << center_.x << ", " << center_.y << ", " << center_.z << ", Radius: " << radius_;
  return os;
}


// own Methods:
HitPoint Sphere::intersect(Ray const& ray) const
{
  // returns hit_point with false if no hit; with true and other parameters if hit
  float distance = 0.0f;
  bool hit = glm::intersectRaySphere(ray.origin_, ray.direction(), center_,
    radius_ * radius_, distance);

  if (hit)
  {
    return HitPoint{ true, distance, ray.origin_ + distance * ray.direction(), ray.direction(), get_name(), get_color()};
  }
  else
  {
    return HitPoint{false};
  }
}

// Sources:
// https://studyflix.de/mathematik/volumen-kugel-2606?timestamp=0