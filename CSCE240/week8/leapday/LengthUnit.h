// Copyright 2024 CSCE240-003
// Define a class for units of length
#ifndef _LENGTHUNIT_H_
#define _LENGTHUNIT_H_

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;

// class definition
class LengthUnit {
  // here we're granting the stream insertion operator direct access to
  // all the members of our class
  // the operator will take a LengthUnit& on the right
  // returns a ostream& so that the operations can cascade
  // ie cout << u << endl;  ==   cout << u; cout << endl;
  // since the left operand is not a LengthUnit, this operator can't
  // be a member of our class, so we'll make it a friend
  friend ostream& operator << (ostream&, const LengthUnit&);

// Google style: public, protected, private indented 1 space
// public members
 public:
  // one show_full_name variable for the entire class
  static bool show_full_name;
  static bool show_conversion_factor;

  // default constructor - constructor that can take 0 arguments
  // since this constructor CAN be called with one argument, we mark it as
  // explicit to ensure that objects aren't implicitly created out of doubles
  explicit LengthUnit(string name = "unknown", double factor = 1,
                      string abbr = "?");

  // destructor - there can be exactly one - at the moment just for show
  //              needed if there's any additional housecleaning that
  //              shoudl occur when we're finished with an object
  ~LengthUnit() { cout << "Destroying " << _conversion_factor << endl; }

  // mutator / set function for conversion factor
  bool SetConversionFactor(double factor);
  bool SetUnitName(string unit);
  bool SetUnitAbbr(string abbr);
  // accessor / get function for conversion factor
  // the const after the parameter list makes this a constant member function
  // meaning that it won't modify the object it's called on
  double GetConversionFactor() const { return _conversion_factor; }
  string GetUnitName() const { return _unit_name; }
  string GetUnitAbbr() const { return _unit_abbr; }

// private members
 private:
  // Google style: private data member names begin with underscore
  double _conversion_factor;  // must be positive
  // unit name and abbreviation e.g. centimeters cm
  string _unit_name;
  string _unit_abbr;
};

#endif
