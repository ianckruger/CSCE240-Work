// Copyright 2024 Ian Kruger
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include"PixelShape.h"

namespace CSCE240_Program6 {

class Rectangle : public PixelShape {
 private:
  int _length;
  int _width;

 public:
  explicit Rectangle(int length = 2, int width = 1, char pixel = '*');

  // Mutators
  void SetLength(int length);
  void SetWidth(int width);

  // Accessors
  int GetLength() const { return _length; }
  int GetWidth() const { return _width; }

  // Virtual Inherited print function
  void Print(bool fill = true) const override;
  // virtual Inherited operator overload
  Rectangle& operator *= (double right) override;
  // virtual deconstructor
  virtual ~Rectangle();
};
}  // namespace CSCE240_Program6

#endif
