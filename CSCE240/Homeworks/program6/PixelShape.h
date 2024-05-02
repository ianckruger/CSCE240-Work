// Copyright 2024 Ian Kruger
#ifndef _PIXELSHAPE_H_
#define _PIXELSHAPE_H_

#include<iostream>
#include<string>
using std::ostream;
using std::string;

namespace CSCE240_Program6 {

class PixelShape {
 // Private Data Members
 private:
  string _name;
  char _pixel_character;
 // Public member functions
 public:
  // Constructor for basic pixel
  explicit PixelShape(string name = "?",
          char pixel = '*');
  // Mutator functions
  void SetPixel(char pixel);
  void SetName(string name);
  // Accessor functions
  string GetName() const { return _name; }
  char GetPixel() const { return _pixel_character; }

  // Virtual Print Function
  virtual void Print(bool fill = true) const;
  // Virtual overload asssignment operator
  virtual PixelShape& operator *= (double right) = 0;
  // Virtual Destructor
  virtual ~PixelShape() {}
};
}  // namespace CSCE240_Program6

#endif
