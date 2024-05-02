// Copyright 2024 Ian Kruger
#include"PixelShape.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;


namespace CSCE240_Program6 {
  // Constructor with default arguments for length checks
  PixelShape::PixelShape(string name, char pixel) :
                         _name(name), _pixel_character(pixel) {
    if (name.length() < 1)
      SetName("?");
    if (pixel < 33 || pixel > 126)
      SetPixel('*');
  }
  // Set the pixel character as long as it is 36-126
  void PixelShape::SetPixel(char pixel) {
    if (pixel >= 33 && pixel <= 126)
      _pixel_character = pixel;
  }
  // Set the shape name as long as it is more than a character
  void PixelShape::SetName(string name) {
    if ( name.length() >= 1)
      _name = name;
  }
  // Virtual print function to be inherited
  void PixelShape::Print(bool fill) const {
    cout << "Pixel Shape Name " << _name << endl;
  }

}  // namespace CSCE240_Program6
