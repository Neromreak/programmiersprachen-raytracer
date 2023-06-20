#include "shape.hpp"
#include "glm/vec3.hpp"

#ifndef BOX_HPP
#define BOX_HPP

class Box : public Shape
{
public:
  // Constructors:
  Box();
  Box(std::string const& name, Color const& color);
  Box(glm::vec3 const& v3_min, glm::vec3 const& v3_max);
  Box(glm::vec3 const& v3_min, glm::vec3 const& v3_max, std::string const& name, Color const& color);

  // Methods
  
  float area() const override;
  float volume() const override;
  
  // Getter for Tests:
  glm::vec3 const& get_min_test() const { return v3_min_; };
  glm::vec3 const& get_max_test() const { return v3_max_; };

private:
  glm::vec3 v3_min_{ 0.0f, 0.0f, 0.0f };
  glm::vec3 v3_max_{ 1.0f, 1.0f, 1.0f };
};

#endif