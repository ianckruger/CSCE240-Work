//copyright me
//functions defined in class on 1/30/2024

//write a function that takes two int variables and swaps their values

// expected cpplint style error for using the path to the file in the
// ifndef/define/endifs below

#ifndef _JAN30FUNCTIONS_H_
#define _JAN30FUNCTIONS_H_

void SwitchValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void SwitchValues(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

//write a pay function

//include default arguments
double Pay(double, double=7.25, double=1.5);
double Pay(double hours, double wage, double OTrate) {
    double pay = hours * wage;
    if (hours > 40) {
        pay  += (hours - 40) * (wage * (OTrate - 1));
        //the original 10 is already payed above, so this calculates the extra dollars 
    }
    return pay;
}

// recursive functions
// write a factorial function
int factorial(int n, int total) {
    if (n < 2) {
        return total;
    }
    else {
        factorial(n-1, total*n);
    }
}

int RecursiveFactorial(int n) {
    if(n<0) {
        return 0;
    } else if (n==1 || n==0) {
        return 1;
    } else {
        return n * RecursiveFactorial(n-1);
    }
}

//fibinachi sequence

int Fib(int n) {
    if ( n <0) {
        return -1;
    } 
    if ( n==0 || n ==1) {
        return 1;
    }
    return Fib(n-1) + Fib(n-2);
}
#endif