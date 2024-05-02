

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<cstdlib>
#include<ctime>
#include"arrayfunctions.h"

int main() {
    const int kRowSize = 5;

    int big_array[kRowSize][kColSize] = {{1,2,3}, {5,7,10,11}, {8}, {6,3}};
    OutputArray(big_array, kRowSize);

    OutputArray(big_array[1], kColSize); // calls one from tuesday
    return 0;

    int column_totals[kColSize];
    ColumnSums(big_array, kRowSize, column_totals);

}