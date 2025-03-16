#include <stdio.h>

int leapyear(int n) {  // Function to check if a year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    char d = 'f';  // Initialize the variable d to 'f'
    char ans;  // Initialize the variable ans accordingly

    // Take an integer input from the user
    scanf("%d", &n);

    // Determine if the year is a leap year and initialize ans accordingly
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = 'y';
    } else {
        ans = 'n';
    }

    // Start an infinite loop to find the next Friday the 13th
    while (1) {
        if (leapyear(n)) {  // Check if n is a leap year
            if (d == 'm') {  // Update d and n based on the current day
                d = 'w';
                n += 1;
            } else if (d == 't') {
                d = 't';
                n += 1;
            } else if (d == 'w') {
                d = 'f';
                n += 1;
            } else if (d == 't') {
                d = 's';
                n += 1;
            } else if (d == 'f') {
                d = 's';
                n += 1;
            } else if (d == 's') {
                d = 'm';
                n += 1;
            }
        } else {
            if (d == 'm') {
                d = 't';
                n += 1;
            } else if (d == 't') {
                d = 'w';
                n += 1;
            } else if (d == 'w') {
                d = 't';
                n += 1;
            } else if (d == 't') {
                d = 'f';
                n += 1;
            } else if (d == 'f') {
                d = 's';
                n += 1;
            } else if (d == 's') {
                d = 'm';
                n += 1;
            }
        }

        // Check if the current day is Friday and the year is a leap year or not
        if (d == 'f' && ans == 'y' && leapyear(n)) {
            break;  // Exit the loop if the condition is met
        } else if (d == 'f' && ans == 'n' && !leapyear(n)) {
            break;  // Exit the loop if the condition is met
        }
    }

    // Print the final year after finding the next Friday the 13th
    printf("%d\n", n);

    return 0;
}
