#include <stdio.h> // Including standard input-output library

// Function to check if a given year is a leap year or not
int check_leap(int y) {
    // Returning 1 (true) if the given year is divisible by 400,
    // or if it is divisible by 4 and not divisible by 100
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    // Declaring variables
    int y, i;
    int sum = 0; // Initializing the sum variable to 0
    int leap; // Variable to store if the input year is a leap year

    // Reading an integer value from the user input
    scanf("%d", &y);

    // Checking if the given year is a leap year or not
    leap = check_leap(y);

    // Starting the loop from the year + 1
    for (i = y + 1; ; i++) {
        // Checking if the current year is a leap year or not
        if (check_leap(i)) {
            // If the current year is a leap year and the previous year was also a leap year,
            // then print the current year and exit the loop
            sum += 366;
            if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
                printf("%d\n", i);
                return 0; // Exit the program
            }
        } else {
            // If the current year is not a leap year, then add 365 to the sum
            sum += 365;
        }

        // Checking if the sum is divisible by 7
        if (sum % 7 == 0) {
            // If the current year is a leap year and the previous year was also a leap year,
            // or if the current year is not a leap year and the previous year was not a leap year,
            // then continue to the next iteration of the loop
            if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
                continue;
            }

            // If the conditions are not met, then print the current year and exit the loop
            printf("%d\n", i);
            return 0; // Exit the program
        }
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
