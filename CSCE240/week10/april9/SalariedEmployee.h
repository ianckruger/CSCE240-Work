// Copyright 2024 CSCE240
// Define a SalariedEmployee class
#ifndef _SALARIED_EMPLOYEE_H_
#define _SALARIED_EMPLOYEE_H_

#include<string>
using std::string;
#include"Employee.h"

namespace CSCE240_Employees {

class SalariedEmployee : public Employee {
 public:
  SalariedEmployee(string first = "Jane", string last = "Doe",
                    string job_title = "TBD", int pays = 52, double salary = 0);

  ~SalariedEmployee() {
    std::cout << "~SalariedEmployee() called" << std::endl;
  }

  void SetSalary(double s);
  double GetSalary() const { return _annual_salary; }

  // NOTE: virtual function doesn't have to be overridden, but we can
  void Print() const override;

  double Pay() const override { return _annual_salary / GetPaysPerYear(); }

 private:
  double _annual_salary;
};  // end class SalariedEmployee

}  // end namespace CSCE240_Employees

#endif
