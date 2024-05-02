// Copyright 2024 CSCE240-003
// implement the functionalty of the Length class
#include"Length.h"
#include"LengthUnit.h"

Length::Length(double v, const LengthUnit& lu) : _unit("meters", 1, "m") {
  SetValue(v);
  _unit = lu;
}

bool Length::SetValue(double v) {
  if ( v >= 0 )
    _value = v;
  return _value == v;
}

void Length::SetUnit(const LengthUnit& lu) {
  _unit = lu;
}
