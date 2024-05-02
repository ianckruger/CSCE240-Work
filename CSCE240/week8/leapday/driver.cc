// Copyright 2024 CSCE240-003
// test leap day functionality
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ofstream;
#include<string>
using std::string;
#include"LengthUnit.h"
#include"Length.h"

int main() {
  LengthUnit u1("centimeters", 0.01, "cm"), u2("inches"), u3("meters", 1, "m");
  LengthUnit::show_full_name = true;
  cout << u1 << "\n" << u2 << "\n" << u3 << endl;
  ofstream myfile("some_file.txt");
  myfile << u1 << endl;
  Length l;
  cout << l.GetValue() << " " << l.GetUnit() << endl;
  Length l2(5, u1);
  cout << l2.GetValue() << " " << l2.GetUnit() << endl;
  return 0;
}
