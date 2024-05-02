// Copyright 2024 Ian Kruger
#include"PixelShape.h"
#include"Rectangle.h"
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Program6 {
  // Constructor with default arguments for length checks
  Rectangle::Rectangle(int length, int width, char pixel) :
                       PixelShape("rectangle", pixel),
                       _length(length), _width(width) {
    if (length < 1)
      SetLength(2);
    if (width < 1)
      SetWidth(1);
  }
  // Implementing mutator functions
  void Rectangle::SetLength(int length) {
    if (length >= 1)
      _length = length;
  }

  void Rectangle::SetWidth(int width) {
    if (width >= 1)
      _width = width;
  }

//   The
// operator should multiply the values of the length and width data members by
// the right operand as long as the resulting lengths and widths are at least
// 1. If multiplying the length and width by the right operand would result in
// a length or width that is less than 1, the operation should leave the
// object unchanged
  Rectangle& Rectangle::operator*= (double right) {
    int length = _length * right;
    int width = _width * right;
    if (1 <= length && width >= 1) {
      _length = length;
      _width = width;
    }
    return *this;
  }
  // Uses a print function that has two for loops independent of one another
  void Rectangle::Print(bool fill) const {
    cout << GetName() << endl;

    for (int i = 1; i <= _length; i++) {
        for (int j = 1; j <= _width; j++) {
            if (fill || i == _length || j == _width || i == 1 || j == 1)
              cout << GetPixel() << ' ';
            else
              cout << "  ";
        }
        cout << endl;
    }
  }

  Rectangle::~Rectangle() {}

}  // namespace CSCE240_Program6
