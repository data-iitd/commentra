#include <stdio.h>

// Function to determine if a year is a leap year
int leapyear(int n) {
    if ((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 0))) {
        return 1;  // Return 1 if it is a leap year
    } else {
        return 0;  // Return 0 if it is not a leap year
    }
}

int main() {
    int n;
    char d = 'f';  // Initialize the day variable to 'f' (Friday)
    char ans[3];   // Array to store "ly" or "nly"

    // Read an integer input from the user representing the year
    scanf("%d", &n);

    // Check if the initial year n is a leap year and set the answer accordingly
    if (leapyear(n)) {
        sprintf(ans, "ly");  // "ly" indicates leap year
    } else {
        sprintf(ans, "nly");  // "nly" indicates non-leap year
    }

    // Infinite loop to determine the next occurrence of a specific day
    while (1) {
        // If the current year n is a leap year
        if (leapyear(n)) {
            // Update the day variable and increment the year based on the current day
            if (d == 'm') {
                d = 'w';  // Monday to Wednesday
                n++;
            } else if (d == 't') {
                d = 't';  // Tuesday to Thursday
                n++;
            } else if (d == 'w') {
                d = 'f';  // Wednesday to Friday
                n++;
            } else if (d == 'th') {
                d = 's';  // Thursday to Saturday
                n++;
            } else if (d == 'f') {
                d = 's';  // Friday to Sunday
                n++;
            } else if (d == 'sa') {
                d = 'm';  // Saturday to Monday
                n++;
            } else if (d == 's') {
                d = 't';  // Sunday to Tuesday
                n++;
            }
        } else {
            // If the current year n is not a leap year, update the day variable accordingly
            if (d == 'm') {
                d = 't';  // Monday to Tuesday
                n++;
            } else if (d == 't') {
                d = 'w';  // Tuesday to Wednesday
                n++;
            } else if (d == 'w') {
                d = 'th';  // Wednesday to Thursday
                n++;
            } else if (d == 'th') {
                d = 'f';  // Thursday to Friday
                n++;
            } else if (d == 'f') {
                d = 'sa';  // Friday to Saturday
                n++;
            } else if (d == 'sa') {
                d = 's';  // Saturday to Sunday
                n++;
            } else if (d == 's') {
                d = 'm';  // Sunday to Monday
                n++;
            }
        }

        // Check if we have reached a Friday and the leap year condition matches the answer
        if ((d == 'f') && (strcmp(ans, "ly") == 0) && leapyear(n)) {
            break;  // Exit the loop if it's a leap year and it's Friday
        } else if ((d == 'f') && (strcmp(ans, "nly") == 0) && !leapyear(n)) {
            break;  // Exit the loop if it's not a leap year and it's Friday
        }
    }

    // Print the resulting year
    printf("%d\n", n);

    return 0;
}
