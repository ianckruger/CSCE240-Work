// Copyright 2024 CSCE240
// test employee functionality
#include"Employee.h"
#include"HourlyEmployee.h"
#include"SalariedEmployee.h"

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

using namespace CSCE240_Employees;

// disclaimer: this is not the actual tax rate, do not use this when you file
//             your taxes
double TaxRate(const Employee& e) {
  if ( e.Pay() * 12 > 200000 ) {
    return 0.3;
  } else if ( e.Pay() * 12 > 75000 ) {
    return 0.25;
  } else if ( e.Pay() * 12 > 20000 ) {
    return 0.2;
  }
  return 0;
}

int main() {
  const int kSize = 2;
  Employee * ptr[kSize];
  string first, last, title, answer;
  double hrs, rate, salary;
  for ( int i = 0; i < kSize; ++i ) {
    cout << "Enter the employee's first name: ";
    cin >> first;
    cout << "Enter the employee's last name: ";
    cin >> last;
    cout << "Enter the employee's job title: ";
    cin >> title;
    cout << "Is this an hourly employee (enter 1) or a salaried employee"
         << " (enter 2)?";
    cin >> answer;
    if ( answer == "1" || answer == "hourly" ) {
      cout << "Enter hourly pay rate: $";
      cin >> rate;
      cout << "Enter hours worked this month: ";
      cin >> hrs;
      ptr[i] = new HourlyEmployee(first, last, title, 12, rate, hrs);
    } else {
      cout << "Enter the annual salary: $";
      cin >> salary;
      ptr[i] = new SalariedEmployee(first, last, title, 12, salary);
    }
  }

  for ( int i = 0; i < kSize; ++i ) {
    ptr[i]->Print();
    cout << "Pay this month: $" << ptr[i]->Pay()
         << "\nTax rate: " << TaxRate(*ptr[i]) << endl;
    delete ptr[i];
  }

  return 0;
}
