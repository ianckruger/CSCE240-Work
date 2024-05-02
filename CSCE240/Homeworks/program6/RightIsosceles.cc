// Copyright 2024 Ian Kruger
#include"PixelShape.h"
#include"RightIsosceles.h"
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Program6 {
  RightIsosceles::RightIsosceles(int length, char pixel) :
                                 PixelShape("right isosceles triangle", pixel),
                                 _length(length) {
    if (length < 2)
      SetLeg(2);
  }

  void RightIsosceles::SetLeg(int length) {
    if (length >= 2)
      _length = length;
  }

  // A print function where the for loop depends on the first for loops
  void RightIsosceles::Print(bool fill) const {
    cout << GetName() << endl;

    for (int i = 1; i <= _length; i++) {
      for (int j = 1; j <= i; j++) {
        if ( fill || i == _length || j == i || j == 1)
          std::cout << GetPixel() << ' ';
        else
          cout << "  ";
      }
      cout << endl;
    }
  }
  // overriding the times operatpr
  RightIsosceles& RightIsosceles::operator *= (double right) {
    if ((_length * right) >= 2)
      _length = _length * right;

    return *this;
  }

  RightIsosceles::~RightIsosceles() {}



}  // namespace CSCE240_Program6
