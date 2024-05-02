// Copyright 2024 CSCE240
// Implement the Employee class functionality
#include"Employee.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Employees {

void Employee::Print() const {
  cout << "Employee Name: " << _first_name << " " << _last_name
       << "\nJob Title: " << _job_title
       << "\nPay periods per year: " << _pays_per_year << endl;
}

Employee::Employee(string first, string last, string job_title, int pays) :
    _first_name("Jane"), _last_name("Doe"), _job_title("TBD"),
    _pays_per_year(52) {
  SetFirst(first);
  SetLast(last);
  SetJobTitle(job_title);
  SetPaysPerYear(pays);
}

void Employee::SetFirst(string f) {
  if ( f.length() > 0 )
    _first_name = f;
}

void Employee::SetLast(string l) {
  if ( l.length() > 0 )
    _last_name = l;
}

void Employee::SetJobTitle(string title) {
  if ( title.length() > 0 )
     _job_title = title;
}

void Employee::SetPaysPerYear(int ppy) {
  if ( ppy == 365 || ppy == 52 || ppy == 26 || ppy == 24 || ppy == 12 )
    _pays_per_year = ppy;
}

ostream& operator << (ostream& where, const Employee& who) {
  where << "Employee Name: " << who._first_name << " " << who._last_name
        << "\nJob Title: " << who._job_title << "\nPays Per Year: "
        << who._pays_per_year;
  return where;
}

}  // namespace CSCE240_Employees




