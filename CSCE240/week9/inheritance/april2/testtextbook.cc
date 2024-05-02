// Copyright 2024 CSCE240-003
#include<iostream>
using std::cout;
using std::endl;
#include"Book.h"
#include"Textbook.h"

// cpplint will complain about the line, we're going
// to ignore it because we're going to work with everything
// in this namespace
using namespace csce240_003_book_project;

int main() {
  Textbook b("Some Book", 2020, 3);
  b.SetChapterTitle(1, "Introduction");
  b.SetChapterTitle(2, "The Story");
  b.SetChapterTitle(3, "The End");
  b.SetChapterHasProblemSet(3, true);
  cout << b << endl;

  b.InsertChapter(1, "Preface");
  b.InsertChapter(5, "Appendix");
  b.InsertChapter(3, "And So It Goes");
  cout << b << endl;

  return 0;
}


/*
  Textbook t, t2("Absolute C++", 2018, 3);
  cout << "t = " << t << "\nt2 = " << t2 << endl;
  
  // the line below calls the copy constructor for the Book class (constructor
  // that expects a reference to a Book object
  Book b(t2);
  cout << b << endl;

  // the line below calls the Book class' overloaded assignment operator that
  // takes a Book object as it's right operand
  b = t;
  cout << b << endl;

  // in order for the line below to work, we would need to write a constructor
  // in our Textbook class that takes a Book as an argument
  Textbook t3(b);

  t3 = b; // need to implement this explicitly if we want it to compile/run


  return 0;
}*/
