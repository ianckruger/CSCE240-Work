// Copyright 2024 CSCE240-003
// Implement functionality of the Textbook class
#include"Textbook.h"

namespace csce240_003_book_project {

// base class constructor called in the derived class  constructor's
// member initializer list
Textbook::Textbook() : Book("Textbook") {
  // _title = "textbook";  // private in the base is hidden in derived
}

}  // end namespace csce240_003_book_project
