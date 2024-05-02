#include<cmath> // use double sqrt(double);
                // double pow(double base, double exponent) 
#include"./isPrime.h"

// include in source files to seperate from headers
bool isPrime(int x) {
// signature: function parameter list. In this example isPrime(int)
    if ( x < 2) {
        return false;
    } 
    for ( int i = 2; i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    } 
    return true;
}

double isBigger(double x, double y) {
    if ( x > y) {
        return x;
    } else {
        return y;
    }
}

double isBigger(double x, double y, double z) {
    double max = x;
    if ( y > x) {
        max = y;
    }
    
    if ( z > max) {
        return z;
    } else {
        return max;
    }
}

double distanceBetween(double x1, double x2, double y1, double y2) {
    // gyatt
    return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2));
}


//function to find roots of a quadratic
// ax^2 + bx + c
// function returns how many roots there were
//cpplint will yell about the non constant references ignore message
int roots(double a, double b, double c, double& root1, double& root2) {
    double disc = pow(b, 2) -4 *a * c;
    if (disc < 0) {
        return 0;
    } else if (disc == 0) {
        root1 = (-1 * b + sqrt(disc)) / (2 * a);
        return 1;
    } else {
        root1 = (-1 * b + sqrt(disc)) / (2 * a);
        root2 = (-1 * b - sqrt(disc)) / (2 * a);
        return 2;
    }

}

double average(double one, double two, double three, double four, double five, double six) {
    
}