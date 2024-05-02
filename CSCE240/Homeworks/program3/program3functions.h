// Copyright Ian Kruger CSCE240
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_

#include"p3compares.h"

// pre-conditions: an array with its corresponding size, a
//                 contained value to remove
// post-condition: returns no value, modifies the value of the given 
//                 array by removing values
void RemoveValues(int array[], int size, int remove);

// pre-conditions: an array with its corresponding size, as well as
//                 how many times the given array should be shifted
// post-condition: returns no value, modifies the value of the given
//                 array by shifting the array indeces
void ShiftArray(int array[], int size, int shift);

// pre-conditions: two character arrays with a boolean indicator
//                 of case sensitivity
// post-condition: returns a boolean indiciating if the two given arrays
//                 are anagrams after removing spaces and puncuation
bool IsAnagram(const char x[], const char y[], bool caseSensitive = false);

// pre-conditions: a characert array and its size along side 3 seperate
//                 characters indicating a character value to replace and
//                 two values to replace it with
// post-condition: returns a boolean indiciating if the letters can be
//                 replaced based on the future modified array size
bool Replace1With2(char x[], int size, char find, char replace1, char replace2);

// pre-conditions: a double subscripted array
// post-condition: returns nothing, modifies the values of the given
//                 double subscripted array by swapping rows and columns
void SwapRowsAndColumns(int array[kSquareSize][kSquareSize]);

#endif