#include <stdio.h>

// Function to check if a year is a leap year
int leapyear(int n) {
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the conditions are met, return "y" to indicate that the year is a leap year
        return 1;
    } else {
        // If the conditions are not met, return "n" to indicate that the year is not a leap year
        return 0;
    }
}

int main() {
    // Take an integer input from the user
    int n;
    scanf("%d", &n);

    // Initialize a variable 'd' to keep track of the day of the week for the given year
    int d = 0;

    // Check if the given year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the year is a leap year, set the answer to "ly"
        char ans = 'l';
    } else {
        // If the year is not a leap year, set the answer to "nly"
        char ans = 'n';
    }

    // Keep updating the day of the week and the year until we find the correct answer
    while (1) {
        // Check if the given year is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // If the year is a leap year, update the day of the week accordingly
            if (d == 0) {
                d = 1;
                n += 1;
            } else if (d == 1) {
                d = 2;
                n += 1;
            } else if (d == 2) {
                d = 3;
                n += 1;
            } else if (d == 3) {
                d = 4;
                n += 1;
            } else if (d == 4) {
                d = 5;
                n += 1;
            } else if (d == 5) {
                d = 6;
                n += 1;
            } else if (d == 6) {
                d = 0;
                n += 1;
            }
        } else {
            // If the year is not a leap year, update the day of the week accordingly
            if (d == 0) {
                d = 2;
                n += 1;
            } else if (d == 1) {
                d = 3;
                n += 1;
            } else if (d == 2) {
                d = 4;
                n += 1;
            } else if (d == 3) {
                d = 5;
                n += 1;
            } else if (d == 4) {
                d = 6;
                n += 1;
            } else if (d == 5) {
                d = 0;
                n += 1;
            } else if (d == 6) {
                d = 1;
                n += 1;
            }
        }

        // Check if we have found the correct answer
        if (d == 0 && ans == 'l' && leapyear(n) == 1) {
            // If we have found the correct answer, break out of the loop
            break;
        } else if (d == 0 && ans == 'n' && leapyear(n) == 0) {
            // If we have found the correct answer, break out of the loop
            break;
        }
    }

    // Print the result
    printf("%d", n);

    return 0;
}

