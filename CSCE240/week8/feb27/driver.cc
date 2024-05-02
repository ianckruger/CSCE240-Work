// Copyright 2024 CSCE240-003
// test the functionality of the LengthUnit class
#include"LengthUnit.h"
#include<iostream>
using std::cout;
using std::endl;

void PrintConversionFactor(const LengthUnit& unit) {
  cout << "Conversion factor to meters is " << unit.GetConversionFactor()
       << endl;
}

int main() {
//  PrintConversionFactor(LengthUnit(3.7));
//  return 0;
//}

  // declaring a variable of the LengthUnit type
  // instantiating and object of the LenghtUnit class type
  const LengthUnit some_unit;  // calls the default constructor
  LengthUnit copy_unit = some_unit;  // calls the copy constructor
  copy_unit.SetConversionFactor(0.01);
  cout << "some_unit's conversion factor = " << some_unit.GetConversionFactor()
       << endl;
  cout << "copy_unit's conversion factor = " << copy_unit.GetConversionFactor()
       << endl;
  copy_unit = some_unit;  // calls assignment operator
                          // (not the copy constructor)

  return 0;
}
