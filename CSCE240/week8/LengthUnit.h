#ifndef _LENGTHUNIT_H_
#define _LENGTHUNIT_H_

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;

class LengthUnit {
  
    friend ostream& operator << (ostream&, const LengthUnit&);

  public:

    explicit LengthUnit(String name, String unit, )
    LengthUnit() { _conversion_factor = 1;
    cout << "In the construction!" << endl;
    }

    //destructor
    ~LengthUnit() { cout << "Destroying " << _conversion_factor << endl;}
    
    //mutator / set function for conversion factor
    bool SetConversionFactor(double factor);
    bool SetUnitName(string unit);
    bool SetUnitAbbr(string abbr);
    // accessor / get function for conversion
    double GetConversionFactor() const { return _conversion_factor; } 
    string GetUnitName() const { return _unit_name; }
    string GetUnitAbbr() const {return _unit_abbr; }



  private:

    double _conversion_factor;

    string _unit_name;
    string _unit_abbr;
};

#endif