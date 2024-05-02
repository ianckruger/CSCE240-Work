// Copyright 2024 Ian Kruger

#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

// returns an int (+ for right or - for left) based on the distance from the inputted number 
int ToClosestPrime(int);

//prints out results in cout rather than returns
void PrintPrimesBetween(int upperBound, int lowerBound, bool inputsIncluded = false);

//returns -1 if none is found
int LargestPrimeSequence(int);

// Prints through cout instead of returning
void PrintAsDollarsAndCents(int);

//return false if arguments 2-8 are sufficient to pay for argument 1
// if true, then modify the inputted money in 2-8, and return change as well
// change is returned by increasing the necessary arguments instead of a seperate change variable
bool MakePurchase(int costInCents, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies);


#endif