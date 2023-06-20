#ifndef  SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape
{
public:
  // Constructors
  Shape();
  Shape(std::string name);
  Shape(std::string name, Color color);

  // Pure virtual methods
  virtual float area() const = 0;
  virtual float volume() const = 0;
  
  // Getter for Tests
  std::string const& get_name_test() const;
  Color const& get_color_test() const;
  
protected:
  std::string name_{ "Shape" };
  Color color_{};
};

#endif