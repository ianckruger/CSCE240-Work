//copyright 2024 kruger
#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
using std::cin;
using std::pow;
using std::sqrt;


//creating classes
// struct Name (mixed case) {};  <-- end classes with semicolons
struct Point {
  double x;
  double y;
}; // <--

//struct vs class
//structu default to public, class default to private


// you cant straight print an object so you would need to write a function
// for it
//for class and structure parameters refrences and pointers save space
void PrintPoint(const Point& p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

//function to compute the distance between two points
//save space with refernece parameters or pointers
double Distance(const Point * point1, const Point * point2) {
  return sqrt( pow(point2->x - point1->x, 2) + pow(point2->y - point1->y, 2) );

}

int main() {
    Point a_point, another_point;

    a_point.x = 3;
    a_point.y = 5;
    another_point.x = 7;
    another_point.y = 8;
    PrintPoint(a_point);
    PrintPoint(another_point);

    Point * point_pointer = &a_point;
    cout << (*point_pointer).x << endl; // derefernce the pointer 
    cout << point_pointer->x << endl; //does the same thing as above

    cout << "the distance between two points is " << Distance(&a_point, &another_point) << endl;

    Point bunch_of_points[10];
    for ( int i = 0; i <10; ++i) {
        cout << "Enter a point" << (i+1) << " ";
        cin >> bunch_of_points[i].x >> bunch_of_points[i].y;
    }

    for ( int i = 0; i < 9; i++) {
      cout << "The distance between ";
      PrintPoint(bunch_of_points[i]);
      cout << " and ";
      PrintPoint(bunch_of_points[i+1]);
      cout << " is " << Distance(&bunch_of_points[i], &bunch_of_points[i+1]);
    }

    return 0;


}


/*

int main( int argc, char * argv[]) {
    cout << argc << endl;
    //argc holds the numbers of c string tokens at the command line when the program is invoked
    // argv is the actual values
}

int main() {
    // simplfy char likert [5] [28] = { "Strongly Agree", "Agree", "Neither", "Disagree", "Strongly Disagree" };
    const char * likert [5] = { "Strongly Agree", "Agree", "Neither", "Disagree", "Strongly Disagree" };

    int i = 0, null_count = 0;
    while ( null_count < 5) {
        cout << likert[0][i];
        if ( likert[0][i] == '\0' ) {
            ++null_count;
            cout << endl;
        }
        i++;
    }


  return 0;
}
*/