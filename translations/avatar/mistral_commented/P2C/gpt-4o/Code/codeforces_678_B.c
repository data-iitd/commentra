#include <stdio.h>

// Function to check if a year is a leap year
char leapyear(int n) {
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the conditions are met, return 'y' to indicate that the year is a leap year
        return 'y';
    } else {
        // If the conditions are not met, return 'n' to indicate that the year is not a leap year
        return 'n';
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
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the year is a leap year, set the answer to "ly"
        ans = 'ly';
    } else {
        // If the year is not a leap year, set the answer to "nly"
        ans = 'nly';
    }

    // Keep updating the day of the week and the year until we find the correct answer
    while (1) {
        // Check if the given year is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // If the year is a leap year, update the day of the week accordingly
            switch (d) {
                case 'm':
                    d = 'w';
                    n += 1;
                    break;
                case 't':
                    d = 'th';
                    n += 1;
                    break;
                case 'w':
                    d = 'f';
                    n += 1;
                    break;
                case 'th':
                    d = 'sa';
                    n += 1;
                    break;
                case 'f':
                    d = 's';
                    n += 1;
                    break;
                case 'sa':
                    d = 'm';
                    n += 1;
                    break;
                case 's':
                    d = 't';
                    n += 1;
                    break;
            }
        } else {
            // If the year is not a leap year, update the day of the week accordingly
            switch (d) {
                case 'm':
                    d = 't';
                    n += 1;
                    break;
                case 't':
                    d = 'w';
                    n += 1;
                    break;
                case 'w':
                    d = 'th';
                    n += 1;
                    break;
                case 'th':
                    d = 'f';
                    n += 1;
                    break;
                case 'f':
                    d = 'sa';
                    n += 1;
                    break;
                case 'sa':
                    d = 's';
                    n += 1;
                    break;
                case 's':
                    d = 'm';
                    n += 1;
                    break;
            }
        }

        // Check if we have found the correct answer
        if (d == 'f' && ans == 'ly' && leapyear(n) == 'y') {
            // If we have found the correct answer, break out of the loop
            break;
        } else if (d == 'f' && ans == 'nly' && leapyear(n) == 'n') {
            // If we have found the correct answer, break out of the loop
            break;
        }
    }

    // Print the result
    printf("%d\n", n);

    return 0;
}

// <END-OF-CODE>
