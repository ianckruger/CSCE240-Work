// Copyright 2024 bhipp
// First template function examples
#include<iostream>
using std::cout;
using std::endl;

// compute the average value in an array
template<class T>
T Average(const T the_array[], int size) {
  T sum = 0;
  for ( int i = 0; i < size; ++i )
    sum += the_array[i];
  return sum / size;
}

// find the smallest value in an array
template<class T>
T Smallest(const T the_array[], int size) {
  T min = the_array[0];
  for ( int i = 1; i < size; ++i ) {
    if ( the_array[i] < min ) {
      min = the_array[i];
    }
  }
  return min;
}

int main() {
  const int kSize = 10;
  double num[kSize] = { 1.2, 5.8, 1.4, 3.6, 12, 13.7, -5.2, 6.01, 7, 10 };
  cout << Average(num, kSize) << endl;
  cout << Smallest(num, kSize) << endl;
  const int kSize2 = 7;
  float num2[kSize2] = { 5, 3, 1, 2.1, 0.06, 3.1, -5 };
  cout << Average(num2, kSize2) << endl;
  cout << Smallest(num2, kSize2) << endl;
  cout << Smallest("fguwirnjsdfviwehrd", 18) << endl;
  return 0;
}
