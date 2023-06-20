#include "shape.hpp"

// Constructors
Shape::Shape()
{}
Shape::Shape(std::string name) :
  name_{ name }
{}
Shape::Shape(std::string name, Color color) :
  name_{ name },
  color_{color}
{}

// Getter for Tests
std::string const& Shape::get_name_test() const
{
  return name_;
}
Color const& Shape::get_color_test() const
{
  return color_;

}