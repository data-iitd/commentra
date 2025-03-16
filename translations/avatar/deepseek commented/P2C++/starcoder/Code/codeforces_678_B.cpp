#include <iostream>
using namespace std;

// Function to check if a year is a leap year
bool leapyear(int n) {
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    string d = "f";
    string ans = "ly";

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
        } else if (d == "f" && ans == "nly" &&!leapyear(n)) {
            break;  // Exit the loop if the condition is met
    }

    cout << n << endl;  // Print the final year after finding the next Friday the 13th
    return 0;
}

