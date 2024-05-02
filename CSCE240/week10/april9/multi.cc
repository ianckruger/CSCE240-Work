// Copyright 2024 CSCE240
// generic multiple inheritance example
#include<iostream>
using std::cout;
using std::endl;

class Parent1 {
 public:
  Parent1(int x = 1) {
    _x = x;
    cout << "Parent1(" << x << ")" << endl;
  }
  ~Parent1() {
    cout << "~Parent1()" << endl;
  }
  void Print() const {
    cout << "x (from Parent1) = " << _x << endl;
  }
 private:
  int _x;
};

class Parent2 {
 public:
  Parent2(int x = 5) {
    _x = x;
    cout << "Parent2(" << x << ")" << endl;
  }
  ~Parent2() {
    cout << "~Parent2()" << endl;
  }
  void Print() const {
    cout << "x (from Parent 2) = " << _x << endl;
  }
 private:
  int _x;
};

class Child : public Parent1, public Parent2 { };

int main() {
  Child c;
  c.Parent2::Print();
  return 0;
}





