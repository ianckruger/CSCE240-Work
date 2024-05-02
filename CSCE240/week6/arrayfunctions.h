
#ifndef _ARRAY_FUNCTIONS_H_
#define _ARRAY_FUNCTIONS_H_

const int kColSize = 10;

int LinearSearch(const int array[], int, int);

void InsertionSort(int[], int);

void OutputArray(const int a[][kColSize], int num_rows, int field_width = 5);

void OutputArray(const int a[], int size);

//precondition: sums is an array of kColSize ints
void ColumnSums(const int a[][kColSize], int num_rows, int sums[] );


//function that returns the number of occurences of a character in a character array
//precondition: phrase holds a null character on the end
int CountOccurances(const char phrase[], char find);
#endif