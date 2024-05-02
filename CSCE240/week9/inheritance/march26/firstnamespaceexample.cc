// Copyright 2024 CSCE240-003
// first namespace example
#include<iostream>
using std::cout;
using std::endl;

namespace csce240_section3_example1 {
  int x = 5;
  void greeting() {
    cout << "Hi" << endl;
  }
}

namespace csce240_section2_example2 {
  int x = 7;
  void greeting() {
    cout << "Howdy" << endl;
  }
}

using csce240_section3_example1::x;
using csce240_section2_example2::greeting;
int main() {
  cout << x << endl;
  csce240_section3_example1::greeting();
  greeting();
  return 0;
}
