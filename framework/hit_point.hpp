#include <string>
#include "color.hpp"
#include "glm/vec3.hpp"

#ifndef  HIT_POINT_HPP
#define HIT_POINT_HPP

struct HitPoint
{
  bool hit_{ false };
  float distance_{ 0.0f };
  glm::vec3 pos_{ 0.0f, 0.0f, 0.0f };
  glm::vec3 direction_{ 0.0f, 0.0f, 0.0f };
  std::string hit_obj_name_{ "hit object" };
  Color hit_obj_color_{};
};

#endif