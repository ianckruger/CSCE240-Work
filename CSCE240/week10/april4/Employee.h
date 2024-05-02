// Copyright 2024 CSCE240
// Define the Employee class
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include<iostream>
using std::ostream;
#include<string>
using std::string;

namespace CSCE240_Employees {

class Employee {
  friend ostream& operator << (ostream&, const Employee&);

 public:
  explicit Employee(string first = "Jane", string last = "Doe",
                     string job_title = "TBD", int pays = 52);
  void SetFirst(string f);
  void SetLast(string l);
  void SetJobTitle(string title);
  void SetPaysPerYear(int ppy);
  string GetFirst() const { return _first_name; }
  string GetLast() const { return _last_name; }
  string GetJobTitle() const { return _job_title; }
  int GetPaysPerYear() const { return _pays_per_year; }

  // adding the virtual keyword in front of the function prototype in the
  // base class definition makes calls to this function use dynamic binding
  virtual void Print() const;

  // virtual functions must either be implemented or made "pure virtual"
  // by putting = 0 on the end of the function prototype
  // a class with a pure virtual function is an "abstract class" which means
  // we can't instantiate objects of this class type.
  virtual double Pay() const = 0;

 private:
  string _first_name;
  string _last_name;
  string _job_title;
  int _pays_per_year;
};  // end class Employee

}  // namespace CSCE240_Employees

#endif  // _EMPLOYEE_H_
