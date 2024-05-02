// Copyright 2024 Ian Kruger
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

// this function simplifies the process of checking for a leap year and prevents overly complicated if statements in the main function
bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// this function finds the threshold date based on the intial date entered to determine when the program should end
void findThresholdDate(int& thresholdDay, int& thresholdMonth, int& thresholdYear) {

    // this list stores the day amount of a month in a list, with a 0 for direct month to index correlation
    int dayAmount[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(thresholdYear)) {
            dayAmount[2] = 29;
        }

    int initialYear = thresholdYear;
    int initialDay = thresholdDay;
    int initialMonth = thresholdMonth;

    // Checking for all cases involving a month with 31, 30, 29, and 28 days, specifically for january going into february with less days
    if (dayAmount[initialMonth] == 31) {
        if (initialDay == 31 && initialMonth == 1) {
            if (isLeapYear(initialYear) == false) {
                thresholdDay = 1;
                thresholdMonth = 3;
            }
        } else if ( initialDay == 1) {
            thresholdDay = 30;
            
        } else if ( initialDay == 2) {
            thresholdDay = 31;
        } else {
            thresholdDay = initialDay - 2;
            thresholdMonth = initialMonth + 1;
        }

        if (initialMonth == 12 && initialDay != 1 && initialDay != 2) {
            thresholdMonth = 1;
            thresholdYear += 1;
            
        }
    } else if (dayAmount[initialMonth] == 30) {
        if (initialDay != 1) {
            thresholdDay = initialDay;
            thresholdMonth = initialMonth + 1;
        } else {
            thresholdDay = 30;
        }
    } else if (dayAmount[initialMonth]==28) {
        thresholdDay = initialDay + 1;
        thresholdMonth = initialMonth + 1;
    } else if ( dayAmount[initialMonth]== 29) {
        thresholdDay = initialDay;
        thresholdMonth = initialMonth + 1;
    }

}
  
// this function checks if the inputted date from a user is equal to or past the threshold date determined by the program
bool metThreshDate(int threshMonth, int month, int threshDay, int day, int threshYear, int year) {
    if (month == threshMonth && day == threshDay && year == threshYear)  {
        return true;
    } else if ( month > threshMonth && year <= threshYear) {
        if ( month == 12 && threshMonth == 1) {
            return false;
        } else {
            return true;
        }
    } else if (month <= threshMonth && year > threshYear) {
        return true;
    } else if (month >= threshMonth && day > threshDay && year <= threshYear) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // initialize the parameters for time
    int initialMonth, initialDay, initialYear;
    double balance;
    char type, slash;
    
    // recieve the initial user input
    cin >> initialMonth >> slash >> initialDay >> slash >> initialYear >> balance;

    // this list stores the day amount of each month for easy arithmetic access
    int dayAmount[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(initialYear)) {
            dayAmount[2] = 29;
        }
    
    int thresholdYear = initialYear;
    int thresholdDay = initialDay;
    int thresholdMonth = initialMonth;

    findThresholdDate(thresholdDay, thresholdMonth, thresholdYear);

    // initializing previous month parameters for the function to track time
    int prevMonth, prevDay, prevYear;
    double prevBalance;
    prevMonth = initialMonth;
    prevDay = initialDay;
    prevYear = initialYear;
    prevBalance = balance;

    double trackbalance = balance;
    double total = 0;
    int trackDays = 1;

    bool threshMet = false;
    bool hitQ = false;

    // a while loop that continues until the threshold is passed or the user quits
    while (!threshMet) {

        int month, day, year;
        char x, y;
        cin >> type;
        
        // Checking for q before the other inputs ensure the program works as intended
        if ( type == 'q') {
            hitQ = true;
            break;
        }

        cin >> month >> x >> day >> y >> year >> balance; 

        if ( metThreshDate(thresholdMonth, month, thresholdDay, day, thresholdYear, year) ) {
            threshMet = true;
        } else if ( day < prevDay) {
            if ( month == 1 && prevMonth == 12) {
                if ( year != prevYear + 1) {
                    cout << "Entries must be provided in chronological order." << endl;
                    cout << month << "/" << day << "/" << year << " entered after " << prevMonth << "/" << prevDay << "/" << prevYear << endl;
                    return 0;
                }
            } else if ( month != prevMonth + 1) {
                cout << "Entries must be provided in chronological order." << endl;
                cout << month << "/" << day << "/" << year << " entered after " << prevMonth << "/" << prevDay << "/" << prevYear << endl;
                return 0;
            } 
        }

        // seperate logical statements for determining the balance/day count based on if the threshold was met or not
        if(day < prevDay && !threshMet) {
            int temp = dayAmount[prevMonth];
            total += prevBalance * ((temp+day) - prevDay);
            trackDays += (temp+day)-prevDay;
        } else if(day >= prevDay && !threshMet) {
            total += prevBalance * (day-prevDay);
            trackDays += day - prevDay;
        }

        if (threshMet) {
            if(thresholdDay < prevDay) {
            int temp = dayAmount[prevMonth];
            total += prevBalance * ((temp + thresholdDay + 1) - prevDay);
            trackDays += (temp + thresholdDay) - prevDay;
        } else {
            total += prevBalance * (thresholdDay-prevDay+1);
            trackDays += thresholdDay - prevDay;
        }
        }

        if( type == 'c') {
            trackbalance += balance;
        } else {
            trackbalance -= balance;
            if (trackbalance < 0) {
                cout << "Overdraft on " << month << "/" << day << "/" << year << ". $15 overdraft fee assessed." << endl;
                trackbalance -= 15;
            }
        }

        prevDay = day;
        prevMonth = month;
        prevYear = year;
        prevBalance = trackbalance;
    
 
    } // end of while loop

    if (hitQ) {
        double average = (total + prevBalance)/trackDays;
        cout << std::fixed << std::setprecision(2) << trackDays << "-day average balance (" << initialMonth << "/" << initialDay << "/" << initialYear << "-" << prevMonth << "/" << prevDay << "/" << prevYear << "): $" << average << endl;
    } else if (trackDays != 0) {
        double average = total / trackDays;
        cout << std::fixed << std::setprecision(2) << trackDays << "-day average balance (" << initialMonth << "/" << initialDay << "/" << initialYear << "-" << thresholdMonth << "/" << thresholdDay << "/" << thresholdYear << "): $" << average << endl;
    } else {
        cout << "Cannot calculate average balance with zero trackDays.  " << thresholdMonth << "/" << thresholdDay << "/" << thresholdYear << endl;
    }

    return 0; 

}
