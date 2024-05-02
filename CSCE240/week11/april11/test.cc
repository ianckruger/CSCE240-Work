// Copyright 2024 CSCE240
// test template functions written in our_templates.h
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"our_templates.h"

int main() {
  //  float num1 = 10, num2 = 5;
  // Switch(num1, num2);
  // cout << "num1 = " << num1 << "\nnum2 = " << num2 << endl;
  const int kSize = 10;
  int num[kSize] = { 1, 16, 22, 5, 7, 13, 88, 2, 0, -7 };
  int x;
  QuickSort(num, 0, kSize - 1);
  for ( int i = 0; i < kSize; ++i )
    cout << num[i] << " ";
  cout << endl;
  cout << "What are you looking for? ";
  cin >> x;
  cout << BinarySearch(num, x, 0, kSize - 1) << endl;
  char stuff[] = "Hey how are you doing today?";
  QuickSort(stuff, 0, 27);
  cout << stuff << endl;
  return 0;
}
