// Copyright 2024 CSCE240
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include"LList.h"

int main() {
  LList<string> my_list1;
  string num;
  my_list1.Print();
  do {
    cout << "Enter next value (-1 to exit) ";
    cin >> num;
    // my_list1.AddToHead(num);
    my_list1.AddToTail(num);
    my_list1.Print();
  } while ( num != "-1" );

  // my_list1.ClearList();
  // my_list1.Print();

  while ( my_list1.RemoveFromTail() )  // my_list1.RemoveFromHead() )
    my_list1.Print();

  LList<double> my_list2;
  my_list2.Print();
  return 0;
}
