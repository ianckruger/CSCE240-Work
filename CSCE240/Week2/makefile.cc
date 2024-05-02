// This is the VIM work on makefile
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
int main() {
         double x, y;
         char op;
         // set precision limits the decimal places
         cout << std::setprecision(2)
              << std::setiosflags ( std::ios::showpoint | std::ios::fixed ); // if in scientific notation makes it show the decimal instead
         cout << "Enter an arithemtci expression with one operations (eq 4/3) ";
         cin >> x >> op >> y;
         cout << std::setfill('-'); // sets fill (only do once), it will put the spaces before the print as -
         cout << std::setw(10) << x <<  " " << op << " " << y << endl; // setw sets the width of space before the print/cout

         if ( op == '/' )
                 cout << x / y << endl;
         else if ( op == '+' )
                 cout << x + y << endl;
         else if ( op == '-' )
                 cout << x - y << endl;
         else if ( op == '*' )
                 cout << x * y << endl;
         else
                 cout << "gyatt" << endl;


         return 0;
 }

 int rand() { //not really random, generates 1 random number each time the file is compiled but will give the same # everytime its ran
    srand(time(0)); // this will get rid of this problem ^^^^
    for ( int i = 0; i < 10; ++i )
        cout << rand() % 6 + 1 << endl;
    return 0;
 }

 //writing own functions


