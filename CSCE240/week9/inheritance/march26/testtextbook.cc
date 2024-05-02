// Copyright 2024 CSCE240-003
#include<iostream>
using std::cout;
using std::endl;
#include"Textbook.h"

// cpplint will complain about the line, we're going
// to ignore it because we're going to work with everything
// in this namespace
using namespace csce240_003_book_project;

int main() {
  Textbook t;
  cout << t << endl;
  t.SetTitle("Absolute C++");
  t.SetNumberOfChapters(5);
  cout << t << endl;
  return 0;
}
