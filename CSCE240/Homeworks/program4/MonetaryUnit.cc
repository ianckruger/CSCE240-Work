// Copyright Ian Kruger CSCE240
// This file defines the functions of the
// Monetary Unit class for storing money varriables

#include"MonetaryUnit.h"
#include<string>
using std::string;
#include<iostream>
using std::ostream;

// Overloading the == operator to compare each individual
// variable of the object rather than object reference
bool operator==(const MonetaryUnit& lhs, const MonetaryUnit& rhs) {
  return lhs._unit_name == rhs._unit_name
         && lhs._unit_symbol == rhs._unit_symbol
         && lhs._unit_exchange == rhs._unit_exchange;
}

// Defining the mutator functions
// String name mutator --> return bool
// based on if name is longer than a space
bool MonetaryUnit::SetName(string name) {
  if (name.length() >= 1)
    _unit_name = name;
  return name == _unit_name;
}

// String symbol mutator --> return bool
// based on if symbol passed in is longer than a space
bool MonetaryUnit::SetSymbol(const string& symbol) {
  if ( symbol.length() >= 1)
    _unit_symbol = symbol;
  return _unit_symbol == symbol;
}

// double value mutator --> return bool
// based on if the value is positive aka greater than 0
bool MonetaryUnit::SetAmountEquivalentTo1Dollar(double value) {
  if ( value > 0 )
    _unit_exchange = value;
  return _unit_exchange == value;
}

// Accessors are already set in the .h file

// This function defines a default constructor for a unit
// defaulting to the standard USD that other units are
// defined around (based on equivalancy variable)
MonetaryUnit::MonetaryUnit(string name, string symbol, double value) :
                              _unit_name("US dollars"),
                              _unit_symbol("$"), _unit_exchange(1) {
  SetAmountEquivalentTo1Dollar(value);
  SetName(name);
  SetSymbol(symbol);
}
