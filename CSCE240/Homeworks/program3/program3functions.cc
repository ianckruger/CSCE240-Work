// Copyright Ian Kruger CSCE240

#include<iostream>
#include<iomanip>
#include"p3compares.h"
#include"program3functions.h"
using std::cout;
using std::cin;
using std::endl;

// this function removes the parameter value remove from the
// given array
void RemoveValues(int array[], int size, int remove) {
    int removedCount = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == remove) {
            int x = i;
            while (x < size) {
                array[x] = array[x+1];
                x++;
            }
            removedCount++;
            i--;
        }
    }
    for (int i = (size-removedCount); i < size; i++) {
        array[i] = -999;
    }
}

// this function shifts a given array based on the
// inputted number of times 
void ShiftArray(int array[], int size, int shift) {
  int i = 0;
  // determine if the shift is right or left
  // shift might not be optimal but I wanted to test as 
  // they are new to me.
  switch (shift > 0 ? 1 : -1) {
      case 1:
        while (i < shift) {
          int temp = array[0];
            for (int j = 0; j < size - 1; ++j) {
              array[j] = array[j + 1];
            }
            array[size - 1] = temp;
            i++;
        }
        break;
      case -1:
        while (i > shift) {
          int temp = array[size - 1];
            for (int j = size - 1; j > 0; --j) {
                array[j] = array[j - 1];
            }
            array[0] = temp;
          i--;
        }
        break;
    }
}

// this function returns a boolean value based on if the 
// given character value is a-zA-Z
bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// this function determines if the two given character arrays
// are anagrams of one another once whitespace characters and
// punctuation are removed from the arrays
bool IsAnagram(const char x1[], const char y1[], bool caseSensitive ) {
    int lenX = 0;
    int lenY = 0;

    // find the size for boolean return without non-alpha characters
    int trackSpace = 0;
    while ( x1[lenX] != '\0' ) {
      if ( !isLetter(x1[lenX]) )
        trackSpace++;
      lenX++;
    }

    int trackSpace2 = 0;
    while (y1[lenY] != '\0') {
      if (!isLetter(y1[lenY]))
        trackSpace2++;
      lenY++;
    }

    if ((lenX-trackSpace) != (lenY-trackSpace2))
      return false;


    // create two new arrays based on alpha size
    char xJustChar[lenX-trackSpace+1];
    char yJustChar[lenY-trackSpace2+1];

    // add alpha chars to new arrays
    int tracker = 0;
    for (int i = 0; i < lenX; i++) {
      if (isLetter(x1[i])) {
        xJustChar[tracker] = x1[i];
        tracker++;
      }
    }

    tracker = 0;
    for (int i = 0; i < lenY; i++) {
      if (isLetter(y1[i])) {
        yJustChar[tracker] = y1[i];
        tracker++;
      }
    }

    // 52 = 26 *2 for all alpha char
    // makeshift hashmaps
    int a[52] = {0};
    int b[52] = {0};


    // go through characters in both char arrays and
    // increment "hashmap" values if found
    for (int i = 0; i < (lenX-trackSpace); ++i) {
        char charX = xJustChar[i];
        char charY = yJustChar[i];

        // uses ASCII values
        if (!caseSensitive) {
          if (charX >= 'a' && charX <= 'z')
              charX -= 32;
          if (charY >= 'a' && charY <= 'z')
              charY -= 32;
        }

          a[charX - 'A']++;
          b[charY - 'A']++;
    }

    // for loop through hashmap values to make sure they all match
    for (int i = 0; i < 52; i++) {
        if (a[i] != b[i])
          return false;
    }
    return true;
}


// this function determines if the given array is large enough to replace a
// given value with two new values, using one additional space per character
bool Replace1With2(char x[], int size, char find, char replace1, char replace2) {
  int track1 = 0;
  int trackOccurances = 0;

  // while there are no newline characters track how many times
  // find is found
  while (x[track1] != '\0') {
      if (x[track1] == find)
        trackOccurances++;
      track1++;
  }

  if (trackOccurances+track1 >= size)
    return false;


  // double nested for loop to shift array for new character without
  // exceeding memory bounds and deleting other array
  for (int i = 0; i < size; i++) {
    if (x[i] == find) {
      for (int j = size - 1; j > i + 1; j--) {
            x[j] = x[j - 1];
        }
      x[i] = replace1;
      x[i+1] = replace2;
    }
  }

  return true;
}


// this function swaps the rows and columns of a double
// subscripted array through a double nested for loop
void SwapRowsAndColumns(int array[kSquareSize][kSquareSize]) {
  for (int i = 0; i < kSquareSize; ++i) {
      for (int j = i + 1; j < kSquareSize; ++j) {
          int temp = array[i][j];
          array[i][j] = array[j][i];
          array[j][i] = temp;
      }
  }
}
