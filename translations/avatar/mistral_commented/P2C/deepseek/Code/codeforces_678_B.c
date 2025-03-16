#include <stdio.h>

// Function to check if a year is a leap year
int leapyear(int n) {
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the conditions are met, return 1 to indicate that the year is a leap year
        return 1;
    } else {
        // If the conditions are not met, return 0 to indicate that the year is not a leap year
        return 0;
    }
}

int main() {
    // Take an integer input from the user
    int n;
    scanf("%d", &n);

    // Initialize a variable 'd' to keep track of the day of the week for the given year
    char d = 'f';

    // Check if the given year is a leap year
    char ans;
    if (leapyear(n)) {
        // If the year is a leap year, set the answer to 'y'
        ans = 'y';
    } else {
        // If the year is not a leap year, set the answer to 'n'
        ans = 'n';
    }

    // Keep updating the day of the week and the year until we find the correct answer
    while (1) {
        // Check if the given year is a leap year
        if (leapyear(n)) {
            // If the year is a leap year, update the day of the week accordingly
            if (d == 'm') {
                d = 'w';
                n += 1;
            } else if (d == 't') {
                d = 't';
                n += 1;
            } else if (d == 'w') {
                d = 'f';
                n += 1;
            } else if (d == 'th') {
                d = 's';
                n += 1;
            } else if (d == 'f') {
                d = 's';
                n += 1;
            } else if (d == 'sa') {
                d = 'm';
                n += 1;
            } else if (d == 's') {
                d = 't';
                n += 1;
            }
        } else {
            // If the year is not a leap year, update the day of the week accordingly
            if (d == 'm') {
                d = 't';
                n += 1;
            } else if (d == 't') {
                d = 'w';
                n += 1;
            } else if (d == 'w') {
                d = 'th';
                n += 1;
            } else if (d == 'th') {
                d = 'f';
                n += 1;
            } else if (d == 'f') {
                d = 'sa';
                n += 1;
            } else if (d == 'sa') {
                d = 's';
                n += 1;
            } else if (d == 's') {
                d = 'm';
                n += 1;
            }
        }

        // Check if we have found the correct answer
        if (d == 'f' && ans == 'y' && leapyear(n)) {
            // If we have found the correct answer, break out of the loop
            break;
        } else if (d == 'f' && ans == 'n' && !leapyear(n)) {
            // If we have found the correct answer, break out of the loop
            break;
        }
    }

    // Print the result
    printf("%d\n", n);

    return 0;
}
