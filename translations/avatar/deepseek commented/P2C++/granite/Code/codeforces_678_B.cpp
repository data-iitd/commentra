
#include <iostream>
#include <string>

using namespace std;

string leapyear(int n) {  // Function to check if a year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        return "y";
    } else {
        return "n";
    }
}

int main() {
    int n;  // Declare an integer variable n
    string d = "f";  // Initialize the variable d to "f"
    string ans;  // Declare a string variable ans

    cout << "Enter an integer: ";
    cin >> n;  // Take an integer input from the user

    // Determine if the year is a leap year and initialize ans accordingly
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        ans = "ly";
    } else {
        ans = "nly";
    }

    // Start an infinite loop to find the next Friday the 13th
    while (true) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {  // Check if n is a leap year
            if (d == "m") {  // Update d and n based on the current day
                d = "w";
                n++;
            } else if (d == "t") {
                d = "th";
                n++;
            } else if (d == "w") {
                d = "f";
                n++;
            } else if (d == "th") {
                d = "sa";
                n++;
            } else if (d == "f") {
                d = "s";
                n++;
            } else if (d == "sa") {
                d = "m";
                n++;
            } else if (d == "s") {
                d = "t";
                n++;
            }
        } else {
            if (d == "m") {
                d = "t";
                n++;
            } else if (d == "t") {
                d = "w";
                n++;
            } else if (d == "w") {
                d = "th";
                n++;
            } else if (d == "th") {
                d = "f";
                n++;
            } else if (d == "f") {
                d = "sa";
                n++;
            } else if (d == "sa") {
                d = "s";
                n++;
            } else if (d == "s") {
                d = "m";
                n++;
            }
        }

        // Check if the current day is Friday and the year is a leap year or not
        if (d == "f" && ans == "ly" && leapyear(n) == "y") {
            break;  // Exit the loop if the condition is met
        } else if (d == "f" && ans == "nly" && leapyear(n) == "n") {
            break;  // Exit the loop if the condition is met
        }
    }

    cout << n;  // Print the final year after finding the next Friday the 13th

    return 0;  // Return 0 to indicate successful execution
}

