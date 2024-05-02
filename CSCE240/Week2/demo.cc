// Copyright 2024 Ian Kruger

// to run do g++ hello.cc to compile then ./a.out
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
//using namespace std; - Never do this!

int main() {

// << is the stream insertion operator
//cout is an osteam object for the standard output device
    cout << "Hello World!\n" << endl; //endl = endline, faster than \n
    int some_number = 0;
    cout << "some_number = " << some_number << endl;
    int y;
    double x, z;
    x = some_number = y = z = 3.7;
    cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
    return 0;
    cout << static_cast<double>(y) / x << endl;
    cout << "Enter an integer ";
    cin >> x;

}
