#include "glm/vec3.hpp"
#include "glm/glm.hpp"

#ifndef RAY_HPP
#define RAY_HPP

struct Ray
{
public:
  // Constructors
  Ray() = default;
  Ray(glm::vec3 origin, glm::vec3 direction):
    origin_{origin},
    direction_{glm::normalize(direction)}
  {}
  

  glm::vec3 origin_{0.0f, 0.0f, 0.0f};

  // Getter/Setter for directions
  void direction(glm::vec3 const& direction)
  {
    direction_ = glm::normalize(direction);
  }
  glm::vec3 const& direction() const
  {
    return direction_;
  }
private:
  glm::vec3 direction_{0.0f, 0.0f, -1.0f}; // normalized
};

#endif

// Sources:
// https://glm.g-truc.net/0.9.4/api/a00131.html (for nomalize())