// Copyright Ian Kruger CSCE240 @2024
// Defining the Monetary Amout Class Information

#include"MonetaryAmount.h"
#include<string>
#include<iostream>
using std::string;
using std::ostream;

// Create a static reference to the boolean
// initialize it as false
bool MonetaryAmount::display_unit_name = false;

// Mutator function for private function
// returns a bool if parameter was set or not
// takes an argument of a constant MonetaryUnit object
bool MonetaryAmount::SetUnit(const MonetaryUnit& unit) {
  _unit_unit = unit;
  return _unit_unit == unit;
}

// Mutator function for private function
// returns a bool if parameter was set or not
// takes an argument of monetary value
bool MonetaryAmount::SetValue(double value) {
  if ( value > 0 )
    _unit_value = value;
  return _unit_value == value;
}

// Defining a default constructor, takes arguments for the
// mutator functions and uses set default object and 0 if not given
MonetaryAmount::MonetaryAmount(double value, const MonetaryUnit& unit) :
                           _unit_value(0), _unit_unit(MonetaryUnit()) {
  SetUnit(unit);
  SetValue(value);
}

// this function overloads the << operator, configured to display
// certain output based on the static variabel display unit name
// returns an output stream filled with objects private values
ostream& operator << (ostream& ret, const MonetaryAmount& lu) {
  if (lu.display_unit_name)
    ret << lu.GetValue() << " " << lu.GetUnit().GetName();
  else
    ret << lu.GetUnit().GetSymbol() << lu.GetValue();
  return ret;
}

// this function overloads the == operator to perform equivalance
// check based on the objects private value data
// takes arguments of two seperate objects on either side of the ==
bool operator==(const MonetaryAmount& lhs, const MonetaryAmount& rhs) {
  double left = lhs.GetValue() / lhs.GetUnit().GetAmountEquivalentTo1Dollar();
  double right = rhs.GetValue() / rhs.GetUnit().GetAmountEquivalentTo1Dollar();
  return left == right;
}

// this function overloads the < operator to perform comparison
// check based on the objects private value data
// takes arguments of two seperate objects on either side of the <
bool operator<(const MonetaryAmount& lhs, const MonetaryAmount& rhs) {
  double left = lhs.GetValue() / lhs.GetUnit().GetAmountEquivalentTo1Dollar();
  double right = rhs.GetValue() / rhs.GetUnit().GetAmountEquivalentTo1Dollar();
  return left < right;
}

// this function overloads the > operator to perform equivalance
// check based on the objects private value data
// takes arguments of two seperate objects on either side of the >
bool operator>(const MonetaryAmount& lhs, const MonetaryAmount& rhs) {
  double left = lhs.GetValue() / lhs.GetUnit().GetAmountEquivalentTo1Dollar();
  double right = rhs.GetValue() / rhs.GetUnit().GetAmountEquivalentTo1Dollar();
  return left > right;
}

// this function overloads the + operator to return sum of the
// two objects in the units of the left operand.
MonetaryAmount operator+(const MonetaryAmount& lhs, const MonetaryAmount& rhs) {
    // Create a new MonetaryAmount object with the
    // converted value to avoid const errors
    double convertedValue = rhs._unit_value * (
                            lhs.GetUnit().GetAmountEquivalentTo1Dollar()
                            / rhs.GetUnit().GetAmountEquivalentTo1Dollar());
    return MonetaryAmount(lhs.GetValue() + convertedValue, lhs.GetUnit());
}

// Get the value that is passed in, and convert
// this object's total money to the passed in value
// takes the argument of the unit that it is being converted to
void MonetaryAmount::ConvertToUnit(const MonetaryUnit& unit) {
  _unit_value *= (unit.GetAmountEquivalentTo1Dollar()
                  / _unit_unit.GetAmountEquivalentTo1Dollar());
  SetUnit(unit);
}
