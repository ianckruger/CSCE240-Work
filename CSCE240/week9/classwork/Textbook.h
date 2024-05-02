
#include"Book.h"

#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_

namspace csce240_003_book_project {

class Textbook : public Book { // extends/ inherits book
 public:
  Textbook(); // default constructor

  // the version of this function in the book class doesnt do exactly what we need
  // so we need to redefine it in the cc file ( im not writing that tho)
  void SetNumberOfChapters(int num);

 private:
  

}

}


#endif 