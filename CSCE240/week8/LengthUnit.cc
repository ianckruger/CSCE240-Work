#include"LengthUnit.h"
#include<string>
#include<iostream>
using std::ostream;
using std::string;

ostream& operator << (ostream& whereto, const LengthUnit& lu) {
  whereto << lu._unit_name << " " << lu._unit_abbr
          << " (conversion factor to meters " << lu._conversion_factor
          << ")";
}


bool LengthUnit::SetUnitName(string name) {
  if ( name.length() >= _unit_abbr.length() )
    _unit_name = name;
  return _unit_name == name; // comparison overload, does not compare address but rather characters
}

void LengthUnit::SetConversionFactor(double factor) {
    if ( factor > 0)
      _conversion_factor = factor;
}