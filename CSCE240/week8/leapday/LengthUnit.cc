// Copyright 2024 CSCE240-003
// implementations for the member functions in LengthUnit
#include"LengthUnit.h"
#include<string>
using std::string;
#include<iostream>
using std::ostream;

bool LengthUnit::show_full_name = false;
bool LengthUnit::show_conversion_factor = false;

// note: only the class can make this a friend - we don't put the
// friend keyword here
ostream& operator << (ostream& whereto, const LengthUnit& lu) {
  if ( LengthUnit::show_full_name )
    whereto << lu._unit_name;
  else
    whereto << lu._unit_abbr;
  if ( LengthUnit::show_conversion_factor )
    whereto << " (conversion factor to meters " << lu._conversion_factor
            << ")";
  return whereto;
}

bool LengthUnit::SetUnitName(string name) {
  // calling the length public member function from string
  if ( name.length() >= _unit_abbr.length() )
    _unit_name = name;  // using the = that is overloaded for string
  return _unit_name == name;  // using the == operator that's overloaded for
                              // string object
}

bool LengthUnit::SetUnitAbbr(string abbr) {
  if ( abbr.length() <= _unit_name.length() )
    _unit_abbr = abbr;
  return _unit_abbr == abbr;
}

// member initializer list - between the () for the constructor and the open
// { for the body of the constructor
// allows us to call the constructor of composed (or inherited) classes in
// the way we would like
LengthUnit::LengthUnit(string name, double factor, string abbr) :
                                     _unit_name("unknown"), _unit_abbr("?") {
    _conversion_factor = 1;
    SetConversionFactor(factor);
    SetUnitName(name);
    SetUnitAbbr(abbr);
    cout << "In the constructor!" << endl;
}



// when implementing a member function outside of the class definition, we
// have to qualify the name of the function with the class name and scope
// resolution operator
bool LengthUnit::SetConversionFactor(double factor) {
  if ( factor > 0 )
    _conversion_factor = factor;  // since SetConversionFactor is a member of
                                  // the class it can directly access any
                                  // member of the class
  return _conversion_factor == factor;
}
