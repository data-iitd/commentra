#include <iostream>
using namespace std;

// Function to determine if a given year is a leap year
bool check_leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    // Create a variable to read input from the user
    int y;
    
    // Read the year input from the user
    cin >> y;
    
    // Check if the input year is a leap year
    bool leap = check_leap(y);
    
    // Initialize variables to keep track of the total days
    int sum = 0;
    
    // Start an infinite loop to find the next matching year
    for (int i = y + 1; ; i++) {
        // Check if the current year is a leap year and add the corresponding days to sum
        if (check_leap(i)) {
            sum += 366;
        } else {
            sum += 365;
        }
        
        // Check if the total number of days is a multiple of 7
        if (sum % 7 == 0) {
            // If the leap year status matches with the input year, print the year and exit
            if ((check_leap(i) && leap) || (!check_leap(i) && !leap)) {
                cout << i << endl;
                return 0;
            }
        }
    }
    
    return 0; // This line will never be reached
}

// <END-OF-CODE>
