// Copyright 2024 CSCE240-003
// implementations for the member functions in LengthUnit
#include"LengthUnit.h"

LengthUnit::LengthUnit(double factor) {
    _conversion_factor = 1;
    SetConversionFactor(factor);
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
