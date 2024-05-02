// Copyright 2024 Ian Kruger
#ifndef _RIGHTISOSCELES_H_
#define _RIGHTISOSCELES_H_
#include"PixelShape.h"
#include<iostream>
#include<string>
using std::string;


namespace CSCE240_Program6 {
class RightIsosceles : public PixelShape {
 private:
  int _length;

 public:
  explicit RightIsosceles(int length = 2, char pixel = '*');

  // Mutators
  void SetLeg(int length);
  // Accessors
  int GetLeg() const { return _length; }
  // Virtual implementation of print
  void Print(bool fill = true) const override;
  // virtual deconstructor
  virtual ~RightIsosceles();
  // virtual operator overide
  RightIsosceles& operator *= (double right) override;
};
}  // namespace CSCE240_Program6

#endif
