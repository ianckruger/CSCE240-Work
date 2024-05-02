//Copyright 2024 Ian Kruger

//header guards below will be included in all header files
// cpplint will request that you put the full file path in the define below
// ^^^ ignore that cpplin error mesage

// you can include multiple functions in this file. this is just the header to condense all inclusions into one, the code for each function is
// in the same named file ending in .cc

#ifndef _SOMEFUNCTIONS_H_
#define _SOMEFUNCTIONS_H_

// cartesian coordinate plane
double distanceBetween(double x1, double x2, double y1, double y2);

//prototype: return type    function name     parameter list
bool isPrime(int x);
//signature: function parameter list

// a function that returns the larger of two real valued arguments
double isBigger(double x, double y);

double isBigger(double x, double y, double z);

//you can overload aka have two functions of the same name, and based on the parameters whatever is entered will be the used function

int roots(double a, double b, double c, double& root1, double& root2);

//function to compute the program average for csce240
// drops the lowest - returns the average of the top 5 values
double average(double, double, double, double, double, double);


#endif // ending the _SOMEFUNCTIONS_H_ header guard


