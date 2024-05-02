// Copyright 2024 Ian Kruger

#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

#include"./isPrime.h"

//functions are for reusability

// write a function that takes an int argument and returns whether or not it is a prime int
//prototype: return type    function name     parameter list

bool isPrime(int x); // functions can be declared after main code if it is initialzed before like so

int main() {
    cout << distanceBetween(1, 3, 2.6, 7) << endl;
    return 0;
}


// use .h for header files. use this for seperate functions that get called in as long as you call them above in the header. 
// isPrime can be in a seperate file, you can do #include"isPrime.h" and it will count
// < > is for library files, " " is for user files
// javastyledoc says you should include file path, but he doesnt care so you can just do "./isPrime.h"