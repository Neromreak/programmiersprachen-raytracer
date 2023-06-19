#include "box.hpp"
#include <glm/vec3.hpp>
#include <numbers>
#include <cmath>

// Constructors
Box::Box()
{}
Box::Box(glm::vec3 const& v3_min, glm::vec3 const& v3_max):
  v3_min_{v3_min},
  v3_max_{v3_max}
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
