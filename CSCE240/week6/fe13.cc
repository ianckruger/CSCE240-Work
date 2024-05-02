
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<cstdlib>
#include<ctime>
#include"arrayfunctions.h"

//when you compile, you make arrayfunctions.o : which is dependent on arrayfunctions.cc and arrayfunctions.h
// feb13.0 : feb13.cc arrayfunctions.h
//     g++ -c -Wall -std=c++17 feb13.cc
// test: feb13.o arrayfunctions.o
//     g++ -Wall -std=c++17 *.o
//     ./a.out

int main() {
    const int kRows = 5;
    const int kCols = 7;
    double double_subscripted_array[kRows][kCols] = {{3.2, 7.8}, {-4,12.1, 2.3}};// each { } is a row, each index is the column of the row 
    //acces from [row][column]

    for ( int i = 0; i < kRows; ++i) {
        for ( int j = 0; j < kCols; j++) {
            cout << double_subscripted_array[i][j] << " ";
        }
        cout << endl;
    }


    srand(time(0));
    const int kSize = 15;
    int some_ints[kSize];
    //populate function ( i didnt write it lol)
    //output array function ( i didnt write it lol)
    int start = clock();
    InsertionSort(some_ints, kSize);
    cout << "insertion" << clock() - start << endl;
    int search_value;
    cout << "What do you want to find papi ";
    cin >> search_value;

    int where = LinearSearch(some_ints, kSize, search_value);
    if (where == -1) {
        cout << "nah" << endl;
        cout << "id win" << endl;
    } else  {
        cout << "stand proud, your int is in array" << endl;
    }
    return 0;

}