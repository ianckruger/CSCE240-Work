// Copyright 2024 CSCE240
// Define an Hourly Employee class
#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_

#include<string>
using std::string;
#include"Employee.h"

namespace CSCE240_Employees {

const double kMinimumWage = 7.25;

class HourlyEmployee : public Employee {
 public:
  explicit HourlyEmployee(string first = "Jane", string last = "Doe",
                     string job_title = "TBD", int pays = 52,
                     double rate = kMinimumWage,
                     double hours = 0);
  void SetHourlyRate(double rate);
  void SetHoursWorked(double hrs);

  double GetHourlyRate() const { return _hourly_rate; }
  double GetHoursWorked() const { return _hours_worked; }

  // inherited virtual Print function
  // the override keyword on the end of the function denotes that we're
  // overriding this virtual function
  void Print() const override;

  double Pay() const override { return _hourly_rate * _hours_worked; }

 private:
  double _hourly_rate;
  double _hours_worked;  // for the current pay period
};  // end class HourlyEmployee

}  // end namespace CSCE240_Employees

#endif
