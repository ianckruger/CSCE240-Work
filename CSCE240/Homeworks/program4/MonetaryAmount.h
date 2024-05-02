// Copyright Ian Kruger CSCE240
// Defining a Class for Monetary Amounts

#ifndef _MONETARYAMOUNT_H_
#define _MONETARYAMOUNT_H_

#include<iostream>
#include<string>
#include"MonetaryUnit.h"
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class MonetaryAmount {
  // Overloading the structure for the == operator for objects
  // in regards to their values
  friend bool operator==(const MonetaryAmount& lhs, const MonetaryAmount& rhs);

  // Overloading the addition operator for two objects
  // in regards to their values
  friend MonetaryAmount operator+(const MonetaryAmount& lhs,
                                  const MonetaryAmount& rhs);

  // Overloading the < comparison operator for two objects
  // in regards to their values
  friend bool operator<(const MonetaryAmount& lhs, const MonetaryAmount& rhs);

  // Overloading the > comparison operator for two objects
  // in regards to their values
  friend bool operator>(const MonetaryAmount& lhs, const MonetaryAmount& rhs);

  // Overloading the assignment operator for an object based on
  // the static boolean display
  friend ostream& operator << (ostream&, const MonetaryAmount&);

 public:
  // A boolean defining how the object displays information
  static bool  display_unit_name;

  // accessor functions for private variables
  double GetValue() const { return _unit_value; }
  MonetaryUnit GetUnit() const { return _unit_unit; }

  // mutator functions for private variables
  bool SetValue(double value);
  bool SetUnit(const MonetaryUnit& unit);

  // Default constructor, explicit as it can be called with
  // one argument
  explicit MonetaryAmount(double value = 0,
                          const MonetaryUnit& unit = MonetaryUnit());

  // Defining the custom method for unit conversion
  void ConvertToUnit(const MonetaryUnit& unit);

 private:
  // private variables defining the monetary amount
  double _unit_value;
  MonetaryUnit _unit_unit;
};


#endif