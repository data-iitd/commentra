
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool check_leap(int y) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int y; // Declaring year
    bool leap; // Declaring leap
    int sum = 0; // Declaring sum
    int mod = 0; // Declaring mod

    // Reading year from user input
    scanf("%d", &y);

    // Checking if the year is a leap year
    leap = check_leap(y);

    // Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
    for (int i = y + 1; ; i++) {
        if (check_leap(i)) { // Checking if the current year is a leap year
            sum += 366; // Adding 366 days for leap years
        } else {
            sum += 365; // Adding 365 days for non-leap years
        }
        if (sum % 7 == 0) { // Checking if the sum of days is a multiple of 7
            if ((check_leap(i) && leap) || (!check_leap(i) && !leap)) { // Checking if the current year's leap status matches the initial leap status
                printf("%d\n", i); // Printing the year if it matches
                return 0; // Exiting the program after printing the year
            } else {
                continue; // Continuing the loop if the leap status does not match
            }
        }
    }

    // End of code
    return 0;
}



