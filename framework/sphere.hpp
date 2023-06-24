#include "shape.hpp"
#include "glm/vec3.hpp"
#include "ray.hpp"
#include "hit_point.hpp"

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public Shape
{
public:
  // Constructors:
  Sphere();
  Sphere(glm::vec3 const& center );
  Sphere(glm::vec3 const& center, float radius);
  Sphere(std::string const& name, Color const& color);
  Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color);

  ~Sphere() override;

  // virtual Methods:
  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  
  // own Methods
  HitPoint intersect(Ray const& ray) const;

  // Getter for Tests:
  glm::vec3 const& get_center_test() const { return center_; };
  float get_radius_test() const { return radius_; };

private:
  glm::vec3 center_{0.0f, 0.0f, 0.0f};
  float radius_{ 1.0f };
};

#endif