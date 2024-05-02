//Copyright 2024 CSCE 240-03
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// for a function, putting const infront of char or int or etc ensure the array doesnt change
// putting it in front of the variable like char * const cptr does somethign else
//you can also put const on both: const char * const cptr


int main() {
    int size = 10;
    int * ptr;
    while ( size > 0) {
        ptr = new int[size];
        for ( int i = 0; i < size; ++i)
          ptr[i] = i % 100;
        cout << "how much do you want bruh";
        cin >> size;
    }
    return 0;
}


/*
// pointers and dynamic memory allocation
int main() {
    int num_tests;
    cout << "";
    cin >> num_tests;
    int * test_grades = new int[num_tests];

    for ( int i = 0; i < num_tests; i++) {
      cout << "Enter test grade " << (i + 1) << " ";
      cin >> test_grades[i];
    }
    return 0;
}
// to prevent a memory leak you should use the delet operator to free up dynamically allocated memory


//function that counts # of words in a phrase
int countWords(const char * cptr) {
    int count = 1;
    while ( *cptr != '\0' ) {
        if ( *cptr == ' ') 
          ++count;
        ++cptr;
    }
    return count;
}


//pointers vs arrays
//pointers can move, arrays alwyas have the same address of the first element
int main() {
    char phrase[] = "What is this";
    cout << phrase << endl; // What is this
    char * ptr = phrase;
    cout << ptr << endl; // What is this
    ptr += 5; //move the pointer
    cout << ptr << endl; // is this
    cout << phrase << " has " <<  countWords(phrase) << endl; //count words expects address, name of the array is an address to the first element
    return 0;
}



//pointers in relation to reference parameters
void SwapInts(int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}

void SwapIntsPointersVersion(int * ptr1, int * ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}


int main() {
    int x = 5;
    int * int_pointer;
    cout << "&x = " << &x << endl;
    cout << "&int_pointer = " << &int_pointer << endl;

    int_pointer = &x;
    cout << "x = " << x << endl;
    cout << "int_pointer" << int_pointer << endl;
    cout << "*int_pointer = " << *int_pointer << endl; 
    *int_pointer = 20;
    cout << "x= " << x << endl;

    int num1=10,num2=37;
    cout << num1 << " " << num2 << endl;
    SwapInts(num1,num2);
    cout << num1 << " " << num2 << endl;
    SwapIntsPointersVersion(&num1, &num2);
    cout << num1 << " " << num2 << endl;
    return 0;

}

*/