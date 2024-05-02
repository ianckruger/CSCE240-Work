//Control structures
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

/*
int main() {
    char c, c2;
    cout << "Enter two non- whitespace characters ";
    cin >> c >> c2;
    cout << "the character read are " << c << " and " << c2 << endl;
    cout << c << " - " << c2 << " = " << c - c2 << endl;
    if ( c > c2 ) {
        cout << c << " - " << c2 << " = " << c - c2 << endl;
    } else {
        cout << c2 << " - " << c << " = " << c2 - c << endl;
    }

    int x;
    cout << "How many major grades are there in your class? ";
    cin >> x;
    cout << " Wow papi " << x << ( x == 1 ? " grade!" : "grades!!!!!!!!!1 >.<") << endl;


    return 0;
}

*/
 int main() {
    char lang;
    do {
    cout << "Enter E for English, S for Spanish, or F for French" << endl;
    cin >> lang;
    } while ( lang != 'E' && lang != 'S' && lang != 'F');
    switch( lang ) {
        case 'E':
            cout << "Hello" << endl;
            break;
        case 'S':
            cout << "Hola" << endl;
            break;
        case 'F':
            cout << "Sault" << endl;
            break;
        default:
            cout << "????" << endl;
            break;
    }

    return 0;

 }


/*
int main() {
    int num, sum = 0;
    int i = 0;
    
    
    while ( i < 10) {
        cout < "Enter an integer " << ++i << " ";
        cin >> num;
        sum += num;
    }
    

    for ( int i = 0; i <10; ++i) {
        cout << "Enter integer " << i + 1 << " ";
        cin >> num;
        sum += num;
    }
    cout << "The average is " << sum / 10.0 << endl;
    cout << "after the loop, i= 10" << endl;
    return 0;

}
*/
// for loops while loops and do while loops
