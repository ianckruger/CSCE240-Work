//copyright me
// test functions

#include"./class.h"
#include<iostream>
using std::cout;
using std::endl;

int main() {
    int num1 = 5, num2 = 12;
    SwitchValues(num1, num2);
    cout << "Num1 = " << num1 << "\nnum2 = " << num2 << endl;

    double real1 = 9.3, real2 = 7.2;
    SwitchValues(real1, real2);
    cout << "real1 =" << real1 << "\nreal2  = " << real2 << endl;
    return 0;
}