#include <iostream>
using namespace std;

// Function to determine if the given year n is a leap year
bool leapyear(int n) {
    // Determine if the given year n is a leap year
    if (n % 400 == 0 or (n % 4 == 0 and n % 100!= 0)) {
        return true;  // Return 'y' if it is a leap year
    } else {
        return false;  // Return 'n' if it is not a leap year
    }
}

// Main function
int main() {
    // Read an integer input from the user representing the year
    int n;
    cin >> n;

    // Initialize the day variable to 'f' (Friday)
    char d = 'f';

    // Check if the initial year n is a leap year and set the answer accordingly
    string ans;
    if (leapyear(n)) {
        ans = "ly";  // 'ly' indicates leap year
    } else {
        ans = "nly";  // 'nly' indicates non-leap year
    }

    // Infinite loop to determine the next occurrence of a specific day
    while (true) {
        // If the current year n is a leap year
        if (leapyear(n)) {
            // Update the day variable and increment the year based on the current day
            if (d =='m') {
                d = 'w';  // Monday to Wednesday
                n += 1;
            } else if (d == 't') {
                d = 'th';  // Tuesday to Thursday
                n += 1;
            } else if (d == 'w') {
                d = 'f';  // Wednesday to Friday
                n += 1;
            } else if (d == 'th') {
                d ='sa';  // Thursday to Saturday
                n += 1;
            } else if (d == 'f') {
                d ='s';  // Friday to Sunday
                n += 1;
            } else if (d =='sa') {
                d ='m';  // Saturday to Monday
                n += 1;
            } else if (d =='s') {
                d = 't';  // Sunday to Tuesday
                n += 1;
            }
        } else {
            // If the current year n is not a leap year, update the day variable accordingly
            if (d =='m') {
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
                d ='sa';  // Friday to Saturday
                n += 1;
            } else if (d =='sa') {
                d ='s';  // Saturday to Sunday
                n += 1;
            } else if (d =='s') {
                d ='m';  // Sunday to Monday
                n += 1;
            }
        }

        // Check if we have reached a Friday and the leap year condition matches the answer
        if (d == 'f' && ans == 'ly' && leapyear(n)) {
            break;  // Exit the loop if it's a leap year and it's Friday
        } else if (d == 'f' && ans == 'nly' &&!leapyear(n)) {
            break;  // Exit the loop if it's not a leap year and it's Friday
    }

    // Print the resulting year
    cout << n << endl;

    return 0;
}

