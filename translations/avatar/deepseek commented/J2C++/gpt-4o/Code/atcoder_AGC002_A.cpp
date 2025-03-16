#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    int a, b; // Declaring two integer variables

    cin >> a; // Reading the first integer input from the user
    cin >> b; // Reading the second integer input from the user

    // Checking if the first number is positive
    if (a > 0) {
        cout << "Positive" << endl; // Printing "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if (b >= 0) {
        cout << "Zero" << endl; // Printing "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if ((b - a + 1) % 2 == 0) {
        cout << "Positive" << endl; // Printing "Positive" if the difference is even
    } 
    else {
        cout << "Negative" << endl; // Printing "Negative" if none of the above conditions are met
    }

    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
