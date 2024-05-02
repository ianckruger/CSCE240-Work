#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"arrayfunctions.h"


int main() {
    const int kMax = 20;
    char words[kMax] = "How's it going?";
    int numbers[kMax] = {2,5,6};

    cout << words << numbers << endl;

    cout << "enter word daddy" << endl;
    //cin >> words; //overloaded to take into the array
    cin.getline(words, kMax);
    cout >> "What i got is " << words << endl;

}


