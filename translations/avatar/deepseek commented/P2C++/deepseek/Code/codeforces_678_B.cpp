#include <iostream>
using namespace std;

bool leapyear(int n) {  // Function to check if a year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    string d = "f";  // Initialize the variable d to "f"

    // Take an integer input from the user
    cin >> n;

    // Determine if the year is a leap year and initialize ans accordingly
    string ans;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        ans = "ly";
    } else {
        ans = "nly";
    }

    // Start an infinite loop to find the next Friday the 13th
    while (true) {
        if (leapyear(n)) {  // Check if n is a leap year
            if (d == "m") {  // Update d and n based on the current day
                d = "w";
                n += 1;
            } else if (d == "t") {
                d = "th";
                n += 1;
            } else if (d == "w") {
                d = "f";
                n += 1;
            } else if (d == "th") {
                d = "sa";
                n += 1;
            } else if (d == "f") {
                d = "s";
                n += 1;
            } else if (d == "sa") {
                d = "m";
                n += 1;
            } else if (d == "s") {
                d = "t";
                n += 1;
            }
        } else {
            if (d == "m") {
                d = "t";
                n += 1;
            } else if (d == "t") {
                d = "w";
                n += 1;
            } else if (d == "w") {
                d = "th";
                n += 1;
            } else if (d == "th") {
                d = "f";
                n += 1;
            } else if (d == "f") {
                d = "sa";
                n += 1;
            } else if (d == "sa") {
                d = "s";
                n += 1;
            } else if (d == "s") {
                d = "m";
                n += 1;
            }
        }

        // Check if the current day is Friday and the year is a leap year or not
        if (d == "f" && ans == "ly" && leapyear(n)) {
            break;  // Exit the loop if the condition is met
        } else if (d == "f" && ans == "nly" && !leapyear(n)) {
            break;  // Exit the loop if the condition is met
        }
    }

    // Print the final year after finding the next Friday the 13th
    cout << n << endl;

    return 0;
}
