#include <stdio.h>
#include <stdlib.h>

// Determine if the given year n is a leap year
int leapyear(int n) {
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return 1;  // Return 1 if it is a leap year
    } else {
        return 0;  // Return 0 if it is not a leap year
    }
}

int main() {
    // Read an integer input from the user representing the year
    int n;
    scanf("%d", &n);

    // Initialize the day variable to 'f' (Friday)
    char d = 'f';

    // Check if the initial year n is a leap year and set the answer accordingly
    char ans;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = 'l';  // 'l' indicates leap year
    } else {
        ans = 'n';  // 'n' indicates non-leap year
    }

    // Infinite loop to determine the next occurrence of a specific day
    while (1) {
        // If the current year n is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // Update the day variable and increment the year based on the current day
            if (d == 'm') {
                d = 'w';  // Monday to Wednesday
                n += 1;
            } else if (d == 't') {
                d = 'th';  // Tuesday to Thursday
                n += 1;
            } else if (d == 'w') {
                d = 'f';  // Wednesday to Friday
                n += 1;
            } else if (d == 'th') {
                d = 'sa';  // Thursday to Saturday
                n += 1;
            } else if (d == 'f') {
                d = 's';  // Friday to Sunday
                n += 1;
            } else if (d == 'sa') {
                d = 'm';  // Saturday to Monday
                n += 1;
            } else if (d == 's') {
                d = 't';  // Sunday to Tuesday
                n += 1;
            }
        } else {
            // If the current year n is not a leap year, update the day variable accordingly
            if (d == 'm') {
                d = 't';  // Monday to Tuesday
                n += 1;
            } else if (d == 't') {
                d = 'w';  // Tuesday to Wednesday
                n += 1;
            } else if (d == 'w') {
                d = 'th';  // Wednesday to Thursday
                n += 1;
            } else if (d == 'th') {
                d = 'f';  // Thursday to Friday
                n += 1;
            } else if (d == 'f') {
                d = 'sa';  // Friday to Saturday
                n += 1;
            } else if (d == 'sa') {
                d = 's';  // Saturday to Sunday
                n += 1;
            } else if (d == 's') {
                d = 'm';  // Sunday to Monday
                n += 1;
            }
        }

        // Check if we have reached a Friday and the leap year condition matches the answer
        if (d == 'f' && ans == 'l' && leapyear(n) == 1) {
            break;  // Exit the loop if it's a leap year and it's Friday
        } else if (d == 'f' && ans == 'n' && leapyear(n) == 0) {
            break;  // Exit the loop if it's not a leap year and it's Friday
        }
    }

    // Print the resulting year
    printf("%d\n", n);

    return 0;
}

