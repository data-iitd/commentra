

#include <stdio.h> // Including standard input/output library
#include <stdbool.h> // Including standard boolean library
#include <time.h> // Including time library for date and time operations

int main() {
    int y; // Declaring variable 'y' to store the year
    printf("Enter a year: "); // Prompt the user to enter a year
    scanf("%d", &y); // Read the year from the user input

    struct tm date = {0}; // Initializing a tm structure to store the date
    date.tm_year = y - 1900; // Setting the year in the tm structure
    date.tm_mon = 1; // Setting the month to January ( tm_mon is 0-based )
    date.tm_mday = 1; // Setting the day to the first day of the year

    time_t t = mktime(&date); // Converting the tm structure to a time_t value representing the number of seconds since the Unix epoch

    bool leap = false; // Declaring boolean variable 'leap' to store the leap status of the year
    if (date.tm_year % 400 == 0 || (date.tm_year % 4 == 0 && date.tm_year % 100!= 0)) {
        leap = true; // Setting 'leap' to true if the year is a leap year
    }

    int sum = 0; // Declaring variable'sum' to store the sum of days
    while (date.tm_year < y) { // Looping until the year reaches the input year
        if (leap) {
            sum += 366; // Adding 366 days for leap years
        } else {
            sum += 365; // Adding 365 days for non-leap years
        }
        t += 86400; // Adding 86400 seconds ( 24 hours ) to the time_t value to move to the next day
        date = *localtime(&t); // Updating the tm structure with the new date
    }

    while (sum % 7!= 0) { // Looping until the sum of days is a multiple of 7
        sum++; // Incrementing the sum of days
        t += 86400; // Adding 86400 seconds ( 24 hours ) to the time_t value to move to the next day
        date = *localtime(&t); // Updating the tm structure with the new date
    }

    printf("The year is: %d\n", date.tm_year + 1900); // Printing the year when the sum of days is a multiple of 7

    return 0; // Returning 0 to indicate successful execution
}

