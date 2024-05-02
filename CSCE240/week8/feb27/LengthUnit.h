// Copyright 2024 CSCE240-003
// Define a class for units of length
#ifndef _LENGTHUNIT_H_
#define _LENGTHUNIT_H_

#include<iostream>
using std::cout;
using std::endl;

// class definition
class LengthUnit {
// Google style: public, protected, private indented 1 space
// public members
 public:
  // default constructor - constructor that can take 0 arguments
  // since this constructor CAN be called with one argument, we mark it as
  // explicit to ensure that objects aren't implicitly created out of doubles
  explicit LengthUnit(double factor = 1);

  // destructor - there can be exactly one - at the moment just for show
  //              needed if there's any additional housecleaning that
  //              shoudl occur when we're finished with an object
  ~LengthUnit() { cout << "Destroying " << _conversion_factor << endl; }

  // mutator / set function for conversion factor
  bool SetConversionFactor(double factor);
  // accessor / get function for conversion factor
  // the const after the parameter list makes this a constant member function
  // meaning that it won't modify the object it's called on
  double GetConversionFactor() const { return _conversion_factor; }

// private members
 private:
  // Google style: private data member names begin with underscore
  double _conversion_factor;  // must be positive
};

#endif
