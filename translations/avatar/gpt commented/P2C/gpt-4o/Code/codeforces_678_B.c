#include <stdio.h>

char leapyear(int n) {
    // Determine if the given year n is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return 'y';  // Return 'y' if it is a leap year
    } else {
        return 'n';  // Return 'n' if it is not a leap year
    }
}

int main() {
    int n;
    // Read an integer input from the user representing the year
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
            switch (d) {
                case 'm':
                    d = 'w';  // Monday to Wednesday
                    n += 1;
                    break;
                case 't':
                    d = 'h';  // Tuesday to Thursday
                    n += 1;
                    break;
                case 'w':
                    d = 'f';  // Wednesday to Friday
                    n += 1;
                    break;
                case 'h':
                    d = 's';  // Thursday to Saturday
                    n += 1;
                    break;
                case 'f':
                    d = 's';  // Friday to Sunday
                    n += 1;
                    break;
                case 's':
                    d = 'm';  // Saturday to Monday
                    n += 1;
                    break;
                case 's':
                    d = 't';  // Sunday to Tuesday
                    n += 1;
                    break;
            }
        } else {
            // If the current year n is not a leap year, update the day variable accordingly
            switch (d) {
                case 'm':
                    d = 't';  // Monday to Tuesday
                    n += 1;
                    break;
                case 't':
                    d = 'w';  // Tuesday to Wednesday
                    n += 1;
                    break;
                case 'w':
                    d = 'h';  // Wednesday to Thursday
                    n += 1;
                    break;
                case 'h':
                    d = 'f';  // Thursday to Friday
                    n += 1;
                    break;
                case 'f':
                    d = 's';  // Friday to Saturday
                    n += 1;
                    break;
                case 's':
                    d = 's';  // Saturday to Sunday
                    n += 1;
                    break;
                case 's':
                    d = 'm';  // Sunday to Monday
                    n += 1;
                    break;
            }
        }

        // Check if we have reached a Friday and the leap year condition matches the answer
        if (d == 'f' && ans == 'l' && leapyear(n) == 'y') {
            break;  // Exit the loop if it's a leap year and it's Friday
        } else if (d == 'f' && ans == 'n' && leapyear(n) == 'n') {
            break;  // Exit the loop if it's not a leap year and it's Friday
        }
    }

    // Print the resulting year
    printf("%d\n", n);
    return 0;
}

// <END-OF-CODE>
