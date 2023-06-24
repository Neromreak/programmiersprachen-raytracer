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


// Getter
std::string const& Shape::get_name() const
{
  return name_;
}

Color const& Shape::get_color() const
{
  return color_;
}


// Virtual Methods
std::ostream& Shape::print(std::ostream& os) const
{
  os << "Name: \"" << name_ << "\", Color[r,g,b]: " << color_.r << ", " << color_.g << ", " << color_.b;

  return os;
}


// Free Functions
std::ostream& operator<< (std::ostream& os, Shape const& shape)
{
  return shape.print(os);
}
// Quelle:
// https://en.cppreference.com/w/cpp/io/basic_ostream
