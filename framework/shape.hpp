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
  
  // Virtual Methods
  virtual std::ostream& print(std::ostream& os) const;

  // Getter
  std::string const& get_name() const;
  Color const& get_color() const;
  
private:
  // Member Variables
  std::string name_{ "Shape" };
  Color color_{};
};

// Free Functions
std::ostream& operator<< (std::ostream& os, Shape const& shape);

#endif