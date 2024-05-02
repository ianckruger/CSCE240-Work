// Copyright 2024 CSCE240
// implement some standard template functions in a header file
#ifndef _OUR_TEMPLATES_H_
#define _OUR_TEMPLATES_H_

// switch values
template<class T>
void Switch(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

// QuickSort - idea find the correct spot for a particular value in the array
//             sort the left subarray
//             sort the right subarray
template<class T>
void QuickSort(T values[], int bottom, int top) {
  if ( bottom >= top )
    return;
  int find_big = bottom + 1, find_small = top;
  while ( find_big < find_small ) {
    while ( find_big < top && values[find_big] <= values[bottom] )
      ++find_big;
    while ( find_small > bottom && values[find_small] >= values[bottom] )
      --find_small;
    if ( find_big < find_small )
      Switch(values[find_big], values[find_small]);
  }
  if ( values[bottom] > values[find_small] )
    Switch(values[bottom], values[find_small]);
  QuickSort(values, bottom, find_small - 1);
  QuickSort(values, find_small + 1, top);
}

// binary search - precondition: values must be sorted
template<class T>
int BinarySearch(const T values[], T search_value, int start, int end) {
  if ( start > end )
    return -1;
  int middle = (start + end) / 2;
  if ( values[middle] == search_value )
    return middle;
  if ( values[middle] > search_value )
    return BinarySearch(values, search_value, start, middle - 1);
  return BinarySearch(values, search_value, middle + 1, end);
}


#endif




