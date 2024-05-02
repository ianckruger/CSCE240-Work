// Copyright 2024 CSCE240-003
// define the length class
#ifndef _LENGTH_H_
#define _LENGTH_H_

#include"LengthUnit.h"

class Length {
 public:
  explicit Length(double value = 0, 
                  const LengthUnit& lu = LengthUnit("meters", 1, "m"));
  bool SetValue(double v);
  void SetUnit(const LengthUnit& lu);
  double GetValue() const { return _value; }
  LengthUnit GetUnit() const { return _unit; }
 private:
  double _value;
  LengthUnit _unit;
};

#endif
