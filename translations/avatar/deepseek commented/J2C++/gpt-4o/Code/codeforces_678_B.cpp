#include <iostream> // Including iostream for input and output
using namespace std; // Using the standard namespace

// Function to check if a year is a leap year
bool check_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0); // Returning true if the year is a leap year
}

int main() {
    int y; // Declaring the year variable
    cin >> y; // Reading the year from user input
    bool leap = check_leap(y); // Checking if the year is a leap year
    int sum = 0; // Initializing sum to accumulate days

    // Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
    for (int i = y + 1; ; i++) {
        if (check_leap(i)) { // Checking if the current year is a leap year
            sum += 366; // Adding 366 days for leap years
        } else {
            sum += 365; // Adding 365 days for non-leap years
        }
        if (sum % 7 == 0) { // Checking if the sum of days is a multiple of 7
            if ((check_leap(i) && leap) || (!check_leap(i) && !leap)) { // Checking if the current year's leap status matches the initial leap status
                cout << i << endl; // Printing the year if it matches
                return 0; // Exiting the program after printing the year
            }
        }
    }
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
