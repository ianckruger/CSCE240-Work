// Copyright 2024 CSCE240
// implement SalariedEmployee functions
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"Employee.h"
#include"SalariedEmployee.h"

namespace CSCE240_Employees {

void SalariedEmployee::Print() const {
  Employee::Print();
  cout << "Annual Salary: $" << _annual_salary << endl;
}

SalariedEmployee::SalariedEmployee(string first, string last, string title,
    int pays, double salary) : Employee(first, last, title, pays) {
  _annual_salary = 0;
  SetSalary(salary);
}

void SalariedEmployee::SetSalary(double sal) {
  if ( sal >= 0 )
    _annual_salary = sal;
}

}  // end namespace CSCE240_Employees
