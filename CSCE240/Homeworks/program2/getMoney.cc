bool getMoney(int index, int totalBill, int& twenties, int& tens, int& fives, int& ones, int& quarters, int& dimes, int& nickels, int& pennies) {
    double totalAmounts[] = {20.00, 10.00, 5.00, 1.00, 0.25, 0.10, 0.05, 0.01};
    int bills[] = {twenties, tens, fives, ones, quarters, dimes, nickels, pennies};
    double converters[] = {2, 2, 5, 4, 2.5, 2, 5};
    
    double extraChange = 0;
    if(bills[index] == pennies) {
        if(pennies >= totalBill) {
            pennies -= totalBill;
            //no need to calculate change i believe
            return true;
        } else {
            return false;                              
        }
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
                if(bills[index+1]==0 && bills[index+2] < 5)
                    if(bills[index]==0) {
                        return false;
                    } else {
                        bills[index] -= 1;
                        extraChange += 0.05;
                    }
                else if(bills[index+1]==0) {
                    bills[index+2] -= 5;
                } else {
                    bills[index+1] -=1;
                }
                totalBill -= 0.5;
            }
            getMoney(index-1, totalBill, twenties, tens, fives, ones, quarters, dimes, nickels,pennies);

        } else {
            totalBill -= bills[index];
            bills[index] = 0;
            totalBill = totalBill * converters[index];
            getMoney(index-1, totalBill, twenties, tens, fives, ones, quarters, dimes, nickels,pennies);
        }
    }
}

    int totalTwenties = 0;
    if (twenties >= totalTwenties) {
            twenties -= totalTwenties;
            // functipon calculate change and update
            return true;
        } else {
            totalTwenties -= twenties;
            twenties = 0;
            int totalTens = totalTwenties *2;
            if (tens >= totalTens) {
                tens -= totalTens;
                // function calculate change and update
                return true;
            } else {
                totalTens -= tens;
                tens = 0;
                int totalFives = totalTens * 2;
                if (fives >= totalFives) {
                    fives -= totalFives;
                    //function calcullate change and updated
                    return true;
                    } else {
                        totalFives -= fives;
                        fives =  0;
                        int totalOnes = totalFives * 5;
                        if (ones >= totalOnes) {
                            ones -= totalOnes;
                            //function calculate change and update
                            return true;
                        } else {
                            totalOnes -= ones;
                            ones = 0;
                            int totalQuarters = totalOnes * 4;
                            if (quarters >= totalQuarters) {
                                quarters -= totalQuarters;
                                //function calculate change and update
                                return true;
                            } else {
                                totalQuarters -= quarters;
                                quarters = 0;
                                int totalDimes = totalQuarters * 2.5;
                                int totalNickels = 0;
                                if (totalDimes % 1 != 0) {
                                    totalNickels = 1;
                                    totalDimes - 0.5;
                                }
                                if (dimes >= totalDimes && totalNickels == 0) {
                                    dimes -= totalDimes;
                                    //function find change and update
                                    return true;
                                } else {
                                    if(dimes>=totalDimes) {
                                        dimes -= totalDimes;
                                    } else {
                                        totalDimes -= dimes;
                                        totalNickels += totalDimes * 2;
                                    } 
                                    if(nickels >= totalNickels) {
                                        nickels -= totalNickels;
                                        //function calculate change
                                        return true;
                                    } else {
                                        totalNickels -= nickels;
                                        nickels = 0;
                                        int totalPennies = totalNickels * 5;
                                        if(pennies >= totalPennies) {
                                            pennies -= totalPennies;
                                            //no need to calculate change i believe
                                            return true;
                                        } else {
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }


