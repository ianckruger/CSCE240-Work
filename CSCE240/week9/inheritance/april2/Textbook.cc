// Copyright 2024 CSCE240-003
// Implement functionality of the Textbook class
#include"Textbook.h"
#include"Book.h"
#include<iostream>
using std::ostream;

namespace csce240_003_book_project {


// redefining the InsertChapter function that exists in Book
void Textbook::InsertChapter(int position, string chapter_title) {
  if ( position >= 1 && position <= GetNumberOfChapters() + 1 ) {
    Book::InsertChapter(position, chapter_title);
    bool * temp = new bool[GetNumberOfChapters()];
    for ( int i = 0, j = 0; i < GetNumberOfChapters(); ++i ) {
      if ( i == position - 1 )
        temp[i] = false;
      else
        temp[i] = _has_problem_set[j++];
    }
    delete [] _has_problem_set;
    _has_problem_set = temp;
  }
}

ostream& operator << (ostream& where, const Textbook& tb) {
  // note: no problem casting a derived class object as a base class object
  // where << static_cast<const Book&>(tb) << " is a textbook!";
  where << "Title: " << tb.GetTitle() << "\nYear Published: "
        << tb.GetYear();
  for ( int i = 0; i < tb.GetNumberOfChapters(); ++i ) {
    where << "\n" << tb.GetChapterTitle(i + 1) << " - "
          << (tb._has_problem_set[i] ? " has " : " doesn't have ")
          << "chapter problem set";
  }
  return where;
}

Textbook& Textbook::operator = (const Textbook& right) {
  Book::operator =(right);
  delete [] _has_problem_set;
  _has_problem_set = new bool[GetNumberOfChapters()];
  for ( int i = 0; i < GetNumberOfChapters(); ++i )
     _has_problem_set[i] = right._has_problem_set[i];
  return *this;
}

Textbook& Textbook::operator = (const Book& right) {
  Book::operator =(right);
  delete [] _has_problem_set;
  _has_problem_set = new bool[GetNumberOfChapters()];
  for ( int i = 0; i < GetNumberOfChapters(); ++i )
     _has_problem_set[i] = false;
  return *this;
}


Textbook::Textbook(const Textbook& to_copy) : Book(to_copy) {
  _has_problem_set = new bool[GetNumberOfChapters()];
  for ( int i = 0; i < GetNumberOfChapters(); ++i )
     _has_problem_set[i] = to_copy._has_problem_set[i];
}

Textbook::Textbook(const Book& to_textbookify) : Book(to_textbookify) {
  _has_problem_set = new bool[GetNumberOfChapters()];
  for ( int i = 0; i < GetNumberOfChapters(); ++i )
     _has_problem_set[i] = false;
}

void Textbook::SetChapterHasProblemSet(int ch, bool val) {
  if ( ch > 0 && ch <= GetNumberOfChapters() )
    _has_problem_set[ch - 1] = val;
}

// base class constructor called in the derived class  constructor's
// member initializer list
Textbook::Textbook(string title, int year, int num) : Book(title, year, num) {
  // _title = "textbook";  // private in the base is hidden in derived
  _has_problem_set = new bool[GetNumberOfChapters()];
  for ( int i = 0; i < GetNumberOfChapters(); ++i )
     _has_problem_set[i] = false;
}

// redefining the SetNumChapters function
void Textbook::SetNumberOfChapters(int n) {
  if ( n >= 0 && n != GetNumberOfChapters() ) {
  // call the Book class version to set up the Book class data members correctly
     Book::SetNumberOfChapters(n);  // without Book:: we'd have infinite
                            // recursion!!
                            // calling this function we're currently writing
                            // instead of the base version
     // and then set up the Textbook data member here
     delete [] _has_problem_set;
     _has_problem_set = new bool[GetNumberOfChapters()];
     for ( int i = 0; i < GetNumberOfChapters(); ++i ) {
       _has_problem_set[i] = false;
     }
  }
}

}  // end namespace csce240_003_book_project
