#include "box.hpp"
#include "color.hpp"
#include <numbers>
#include <cmath>
#include "glm/vec3.hpp"
#include <string>
#include "shape.hpp"

// Constructors
Box::Box()
{}
Box::Box(std::string const& name, Color const& color):
  Shape::Shape{name , color}
{}
Box::Box(glm::vec3 const& v3_min, glm::vec3 const& v3_max):
  v3_min_{v3_min},
  v3_max_{v3_max}
{}
Box::Box(glm::vec3 const& v3_min, glm::vec3 const& v3_max, std::string const& name, Color const& color):
  Shape::Shape{name, color},
  v3_min_{ v3_min },
  v3_max_{ v3_max }
{}


// Methods
float Box::area() const
{
  float x_lenght = std::abs(v3_min_.x - v3_max_.x);
  float y_lenght = std::abs(v3_min_.y - v3_max_.y);
  float z_lenght = std::abs(v3_min_.z - v3_max_.z);
  return x_lenght * z_lenght * 2 + x_lenght * y_lenght * 2 + y_lenght * z_lenght * 2;
}

float Box::volume() const
{
  float x_lenght = std::abs(v3_min_.x - v3_max_.x);
  float y_lenght = std::abs(v3_min_.y - v3_max_.y);
  float z_lenght = std::abs(v3_min_.z - v3_max_.z);
  return x_lenght * y_lenght * z_lenght;
}

std::ostream& Box::print(std::ostream& os) const
{
  Shape::print(os);
  os << ", Min: " << v3_min_.x << ", " << v3_min_.y << ", " << v3_min_.z << ", Max: " << v3_max_.x << ", " << v3_max_.y << ", " << v3_max_.z;
  return os;
}
