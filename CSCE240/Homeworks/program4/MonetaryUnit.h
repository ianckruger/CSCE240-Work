// Copyright Ian Kruger CSCE240
// Defining a Class for Monetary Unit Values

#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;

// defining the class
class MonetaryUnit {
  // friend ostream& operator == (ostream&, const MonetaryUnit&);
  friend bool operator==(const MonetaryUnit& lhs, const MonetaryUnit& rhs);

  // public member
 public:
  // default constructor
  explicit MonetaryUnit(string name = "US dollars", string symbol = "$",
                        double value = 1);
  // Setters
  // set name function
  bool SetName(string name);

  // return bool based on if the symbol was set
  // aka one doesnt exist already and is long enough
  bool SetSymbol(const string& symbol);

  // set dollar exchange rate as long as its positive
  bool SetAmountEquivalentTo1Dollar(double value);

  // Getter functions implemented in class
  string GetName() const { return _unit_name; }
  string GetSymbol() const { return _unit_symbol; }
  double GetAmountEquivalentTo1Dollar() const { return _unit_exchange; }

 private:
  // unit name and abbreviation
  string _unit_name;
  string _unit_symbol;
  double _unit_exchange;  // must be positive
};

#endif
