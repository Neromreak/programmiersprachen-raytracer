#include <glm/vec3.hpp>
#include "shape.hpp"

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public Shape
{
public:
  // Constructors:
  Sphere();
  Sphere(glm::vec3 center);
  Sphere(glm::vec3 center, float radius);

  // Methods:
  
  float area() const override;
  float volume() const override;
  
  // Getter for Tests:
  glm::vec3 const& get_center_test() const { return center_; };
  float get_radius_test() const { return radius_; };

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_ = 1.0f;
};

#endif