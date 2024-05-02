// Copyright 2024 CSCE240
// implement functionality of HourlyEmployee class
#include"HourlyEmployee.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

namespace CSCE240_Employees {

void HourlyEmployee::Print() const {
  Employee::Print();  // calling the base class version
  cout << "Hourly Rate $: " << _hourly_rate
       << "\nHours Worked: " << _hours_worked << endl;
}

HourlyEmployee::HourlyEmployee(string first, string last, string job_title,
                     int pays, double rate, double hours)
                           : Employee(first, last, job_title, pays),
                                 _hourly_rate(kMinimumWage), _hours_worked(0) {
  SetHourlyRate(rate);
  SetHoursWorked(hours);
}


void HourlyEmployee::SetHourlyRate(double rate) {
  if ( rate >= kMinimumWage ) {
    _hourly_rate = rate;
  }
}

void HourlyEmployee::SetHoursWorked(double hrs) {
  if ( hrs >= 0 && 365 * 24 / GetPaysPerYear() )  // max???
    _hours_worked = hrs;
}


}  // end namespace CSCE240_Employees
