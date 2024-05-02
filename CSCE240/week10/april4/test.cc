// Copyright 2024 CSCE240
// test employee functionality
#include"Employee.h"
#include"HourlyEmployee.h"
#include"SalariedEmployee.h"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

using namespace CSCE240_Employees;

int main() {
// Employee e("Al", "Pacicco", "Your Boss", 365);
//  e.Print();
  HourlyEmployee he("Druv", "Patel", "SI", 12, 100, 4);
  he.Print();
  SalariedEmployee se("Rice", "Davis", "Garbage Collector", 10, 200000);
  se.Print();

  Employee * ptr;
  cout << "2 for Hourly Employee or 3 for Salaried ";
  int answer;
  cin >> answer;
//  if ( answer == 1 )
//    ptr = &e;
//  else
  if ( answer == 2 )
    ptr = &he;
  else
    ptr = &se;

  ptr->Print();
  cout << "Pay: $" << ptr->Pay() << endl;
  return 0;
}
