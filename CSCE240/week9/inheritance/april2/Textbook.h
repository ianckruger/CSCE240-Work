// Copyright 2024 CSCE240-003
// Define a Textbook class as a child of the Book class
#include"Book.h"
#include<iostream>
using std::ostream;
#include<string>
using std::string;

#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_

namespace csce240_003_book_project {

class Textbook : public Book {
  // overloading the << operator
  friend ostream& operator << (ostream&, const Textbook&);

 public:
  // Constructor that can be called with 0 to 3 arguments
  explicit Textbook(string title = "unknown", int year = 2024, int num = 0);
  // our class has a pointer as a data member so we need to implement a
  // destructor, copy constructor, and assignment =
  ~Textbook() {
    // NOTE: derived class destructor is called before base class destructor
    //  std::cout << "In ~Textbook()" << std::endl;
    delete [] _has_problem_set;
  }

  Textbook& operator = (const Textbook& right);
  Textbook& operator = (const Book& right);
  // copy constructor
  Textbook(const Textbook& to_copy);
  // "upgrade constructor" / "base-to-derived constructor"
  explicit Textbook(const Book& to_textbookify);

  // the version of this function in the Book class doesn't do exactly what we
  // need it to do for a Textbook object, so we are REDEFINING it here
  void SetNumberOfChapters(int num);

  void SetChapterHasProblemSet(int ch, bool val = true);

  void InsertChapter(int position, string chapter_title);

 private:
  // true/false for each chapter in the textbook
  bool * _has_problem_set;
};  // end Textbook class definition

}  // end namespace csce240_003_book_project

#endif
