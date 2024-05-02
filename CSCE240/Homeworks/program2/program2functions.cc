// Copyright 2024 Ian Kruger
#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<cmath>
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::round;

#include"./program2functions.h"


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

// Checks if x, the new contending string, is larger than the assumed biggest string y
bool isBigger(string x, string y) {
    if ( x.empty() && y.empty()) {
        return false;
    } else if (x.empty()) {
        return false;
    } else if (y.empty()) {
        return true;
    }
    int temp1 = stoi(x);
    int temp2 = stoi(y);
    if (temp1 > temp2) {
        return true;
    } else {
        return false;
    }
}

int ToClosestPrime(int x) {
    if(isPrime(x)) {
        return 0;
    }
    int left = x- 1;
    int right = x + 1;

    while (true) {
        // Since we return the positive int if they are equidistant,
        // check right side first
        if (isPrime(right)) {
            return right - x;
        } else if (isPrime(left)) {
            return left - x;
        } else {
            right += 1;
            left -= 1;
            //not sure if this is necessary as 1 is prime and will reach that before 0 but just in case
            if (left < 0) {
                left = 0;
            }
        }

    }
}

void PrintPrimesBetween(int lowerBound, int upperBound, bool inputsIncluded) {
    bool firstPrint = true;
    // change the bounds if theyre included
    if (!(inputsIncluded)) {
        upperBound -= 1;
        lowerBound += 1;
    }
    // if the bounds exceed each other return 
    if (upperBound < lowerBound) {
        return;
    }
    // iterate through the bounds
    for (int i = lowerBound; i <= upperBound; ++i) {
        cout << i << endl;
        if (isPrime(i) && firstPrint) {
            cout << i << endl;
            firstPrint = false;
        } else if (isPrime(i)) {
            cout << ", " << i << endl;
        }
    } 
    return;
}

//This function gets a number and iterates through each possible sequence of characters to find the largest prime number
// takes a similar approach to the smallest substring without repeating characters
int LargestPrimeSequence(int number) {
    string num = std::to_string(number);
    string largestNum = "";

    if (num.length()==1) {
        if (isPrime(number)) {
            return number;
        } else {
            return -1;
        }
    }

    // iterate through each possible combination and check for largest number thats prime every iteration
    for (int x = 0; x < num.length(); ++x) {
        string tempNum = "";
        char currentChar = num[x];
        tempNum += currentChar;
        if ( isPrime(stoi(tempNum)) && isBigger(tempNum, largestNum)) {
                largestNum = tempNum;
        }
        for (int y = x +1; y <num.length(); y++) {
            char addChar = num[y];
            tempNum += addChar;
            int temp = stoi(tempNum);

            if ( isPrime(temp) && isBigger(tempNum, largestNum)) {
                largestNum = tempNum;
            }
        }
    }
    
    if (largestNum == "") {
        if ( isPrime(num[num.length()-1]) ) {
            char temp = num[num.length()-1];
            largestNum += temp;
        } else {
            return -1;
        }
    }
    int large = stoi(largestNum);
    return large;
    
}


// uses math to divide cents from dollars
void PrintAsDollarsAndCents(int totalCents) {
    int dollars, cents;
    dollars = totalCents/100;
    cents = totalCents%100;
    cout << "$" << dollars << "." << std::setw(2) << std::setfill('0') << cents;
}

// uses the same math from the above function to get the right amount for the money
double getDollarsAndCents(double totalCents) {
    double dollars = totalCents/100;
    double cents = (totalCents - (dollars *100)) / 100;
    double total = dollars + cents;
    return total;
}

// iterates through ahd gives the appropriate change based on the given amount of money
void calculateChange(double excessPayed, double amountDue, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double amountOwed = excessPayed-amountDue;
    if(round(amountOwed) == 0) {
        return;
    }
    int index = 0;
    
    while(amountOwed >0.01) {
        if (amountOwed >= totalAmounts[index]) {
            amountOwed -= totalAmounts[index];
            bills[index] += 1;
        } else {
            index += 1;
            if (index>7) {
                index = 7;
            }
        }
    }
    bills[index] += 1;

    twenties = bills[0];
    tens = bills[1];
    fives = bills[2];
    ones = bills[3];
    quarters = bills[4];
    dimes = bills[5];
    nickels = bills[6];
    pennies = bills[7];
}

// checks through the given bills to see if the total exceeds the cost
bool hasEnough(double cost, int twenties, int tens, int fives, int ones, int quarters, int dimes, int nickels, int pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double total = 0;

    for (int i = 0; i < 8; i++) {
        total += bills[i] * totalAmounts[i];
    }
    return total >= cost;
}


// iterates through and subtracts the money from the user
double getMoney(double total, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double reverseTotalAmounts[] = {0.01, 0.05, 0.10, 0.25, 1.00, 5.00, 10.00, 20.00};
    int reverseBills[] = {pennies, nickels, dimes, quarters, ones, fives, tens, twenties};

    double payWith = 0.0;
    double trackCost = total;
    double trackPayed = 0.0;
    int index = 0;

    for (int i = 0; i < 8; i++) {
        if (reverseTotalAmounts[i] >= total && reverseBills[i] != 0) {
            payWith += reverseTotalAmounts[i];
            reverseBills[i] -=1;
            twenties = reverseBills[7];
            tens = reverseBills[6];
            fives = reverseBills[5];
            ones = reverseBills[4];
            quarters = reverseBills[3];
            dimes = reverseBills[2];
            nickels = reverseBills[1];
            pennies = reverseBills[0];
            return payWith;
        }
    }

    while(trackCost > 0 && index < 8) {   
        if(bills[index] != 0 && trackCost >= totalAmounts[index]) {
            bills[index] -= 1;
            trackCost -= totalAmounts[index];
            trackPayed += totalAmounts[index];
        }
        else {
            index += 1;
        }
    }
        twenties = bills[0];
        tens = bills[1];
        fives = bills[2];
        ones = bills[3];
        quarters = bills[4];
        dimes = bills[5];
        nickels = bills[6];
        pennies = bills[7];
        return trackPayed;

}


// makes a purchase; calls the above functions to avoid long methods
bool MakePurchase(int costInCents, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double total = getDollarsAndCents(costInCents);
    

    bool hasMoney = hasEnough(total, twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
    if(!hasMoney) {
        return false;
    }
    double payed = getMoney(total,twenties, tens, fives, ones, quarters, dimes, nickels, pennies);

    
    calculateChange(payed,total,twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
    return true;
}