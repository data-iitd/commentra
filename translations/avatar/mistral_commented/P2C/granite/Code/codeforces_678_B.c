
#include <stdio.h>

// Function to check if a year is a leap year
char leapyear(int n) {
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        // If the conditions are met, return "y" to indicate that the year is a leap year
        return 'y';
    } else {
        // If the conditions are not met, return "n" to indicate that the year is not a leap year
        return 'n';
    }
}

int main() {
    int n;
    char d = 'f';
    char ans;

    // Take an integer input from the user
    scanf("%d", &n);

    // Check if the given year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        // If the year is a leap year, set the answer to "ly"
        ans = 'l';
    } else {
        // If the year is not a leap year, set the answer to "nly"
        ans = 'n';
    }

    // Keep updating the day of the week and the year until we find the correct answer
    while (1) {
        // Check if the given year is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
            // If the year is a leap year, update the day of the week accordingly
            if (d =='m') {
                d = 'w';
                n++;
            } else if (d == 't') {
                d = 't';
                n++;
            } else if (d == 'w') {
                d = 'f';
                n++;
            } else if (d == 't') {
                d ='s';
                n++;
            } else if (d == 'f') {
                d ='m';
                n++;
            } else if (d =='s') {
                d = 't';
                n++;
            } else if (d =='m') {
                d = 'w';
                n++;
            }
        } else {
            // If the year is not a leap year, update the day of the week accordingly
            if (d =='m') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'w';
                n++;
            } else if (d == 'w') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'f';
                n++;
            } else if (d == 'f') {
                d ='s';
                n++;
            } else if (d =='s') {
                d ='m';
                n++;
            }
        }

        // Check if we have found the correct answer
        if (d == 'f' && ans == 'l' && leapyear(n) == 'y') {
            // If we have found the correct answer, break out of the loop
            break;
        } else if (d == 'f' && ans == 'n' && leapyear(n) == 'n') {
            // If we have found the correct answer, break out of the loop
            break;
        }
    }

    // Print the result
    printf("%d\n", n);

    return 0;
}
// END-OF-CODE