void getMoney(int index, int totalBill, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double converters[] = {2, 2, 5, 4, 2.5, 2, 5};
    
    double extraChange = 0;
    if(bills[index] == pennies) {
        if(pennies >= totalBill) {
            pennies -= totalBill;
            return;
    }
    if (bills[index] >= totalBill) {
        bills[index] -= totalBill;
        //find change funciton
        // return change
    } else {
        if (bills[index]==quarters) {
            totalBill -= bills[index];
            bills[index] = 0;
            totalBill = totalBill * converters[index];
            if (totalBill % 1 != 0) {
                if(bills[index+1]==0 && bills[index+2] < 5) {
                    if(bills[index]==0) {
                        return false;
                    } else {
                        bills[index] -= 1;
                        extraChange += 0.05;
                    }
                } else if(bills[index+1]==0) {
                    bills[index+2] -= 5;
                } else {
                    bills[index+1] -=1;
                }
                totalBill -= 0.5;
            }
            return getMoney(index-1, totalBill, twenties, tens, fives, ones, quarters, dimes, nickels,pennies);

        } else {
            totalBill -= bills[index];
            bills[index] = 0;
            totalBill = totalBill * converters[index];
            return getMoney(index-1, totalBill, twenties, tens, fives, ones, quarters, dimes, nickels,pennies);
        }
    }
}

/*
int trackOnes = 0;
    while (amountOwed > 1.00) {
        amountOwed -= 1;
        trackOnes += 1;
    }
    if (trackOnes > 5) {
        int temp = trackOnes % 5;
        ones += temp;
        trackOnes -= temp;
        int trackFives = trackOnes /5;
        if (trackFives>1) {
            fives += trackFives% 2;
            trackFives -= trackFives%2;
            int trackTens = trackFives /2;
            if (trackTens>1) {
                tens += trackTens% 2;
                trackTens -= trackTens%2;
                int trackTwenties = trackTens /2;
                twenties += trackTwenties;
        } else {
            tens += trackTens;
        }
        } else {
            fives += trackFives;
        }
    } else {
        ones += trackOnes;
    }*/


    /*
while (true) {
        if (trackLeft >= totalAmounts[x]) {
            if (bills[x] > 0) {
                bills[x] -= 1;
                trackLeft -= totalAmounts[0];
            } else {
                x++;
            }
        } else {
            x++;
        }
    } 
    
    
    double startingAmount;

    if ( total >= 0.05 && total < 20) {
        for (int i = 0; i < sizeof(totalAmounts); ++i) {
            if ( total > totalAmounts[i] && total <= totalAmounts[i+1]) {
                startingAmount = totalAmounts[i+1];
                break;
            }
        }
    } else if ( total < 0.05) {
        if( pennies > 4) {
             pennies -= (total / 0.01);
        } else if (nickels > 1) {
            nickels -= 1;
            pennies += 
        }
    }
    */

double getChange(int total,int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};

    double x = 0;
    if (total >= 20) {
        x = 20;
        int totalBills = 1;
        while ( x < total) {
            x += 20;
            totalBills ++;
        }

        if (twenties >= totalBills) {
            twenties -= totalBills;
            return x - total;
        } else {
            int temp = twenties;
            totalBills -= temp;
            twenties = 0;

        }
    }

}

int findClosestAmount(double total, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double minDifference = 20.00 - total;
    int index = 0;


    for(int i = 0; i < 8; i++) {
        double cost = totalAmounts[i];
        double temp = cost - total;
        if (temp < 0) {
            temp *= -1;
        }
        if (temp < minDifference && bills[i] != 0) {
            minDifference = temp;
            index = i;
        }
    }
    return index;

}