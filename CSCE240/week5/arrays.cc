//copyright ian

#include<iostream>
using std::cout;
using std::endl;
#include<cstdlib>


// use const if the address of the array will not be modified
void OutputArray(const int a[], int size);

void OutputArray(const int a[]);

double AverageArray(const int nums[], int size);


int main() {
    const int kSize = 15;
    // we can initialize the values when the array is declared with a comma-seperate list of values
    double some_reals[kSize] = {2.3, 6.7, -4.97};

    cout << some_reals << endl;
    //this will give the address of the array, where the array starts
    // probably be a hexidecimal memory address location
    cout << some_reals[1] << endl;
    // out 6.7
    cout << some_reals[10] << endl;
    // out 0

    cout << sizeof(double) << endl;

    int more_ints[] = {1,5,6};
    OutputArray(more_ints,3);
    return 0;
}