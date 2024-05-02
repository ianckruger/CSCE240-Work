#include<iostream>
using std::cout;
using std::endl;
#include<cstdlib>
#include"arrayfunctions.h"

int LinearSearch(const int the_array[], int size, int lookin4) {
    int found_position = -1;
    for ( int i = 0; i < size && found_position == -1; i++) {
        if ( the_array[i] == lookin4) {
            found_position = i;
        }
        return found_position;
    }
}

void InsertionSort(int array[], int size) {

    for ( int sorted = 1; sorted < size; sorted++) {
        int i = sorted;
        while (i > 0 && array[i] < array[i-1] ) {
            int temp = array[i];
            array[i] = array[i-1];
            array[i-1] = temp;
            --i;
        }
    }
}

void OutputArray(const int a[][kColSize], int num_rows, int field_width) {
    for ( int = 0; i < num_rows; i++) {
        for( int j = 0; j < kColSize; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void ColumnSums(const int a[][kColSize], int num_rows, int sums[]) {
    fpor ( int j=0; j< kColSize; j++) {
        sums[j] = 0;
        for ( int i =0; i < num_rows; ++i) {
            sums[j] += a[i][j];
        }
    }
}

int CountOccurances(const char phrase[], char find) {
    int count = 0, i = 0;
    while ( phrase[i] != '\0') {
        if ( phrase[i] == find) {
            count++;
        }
        i++;
    }
    return count;
}