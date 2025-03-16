#include <iostream>

using namespace std;

int main() {
    // Declare an integer variable to hold the input seconds
    int S;

    // Read an integer input from the user representing seconds
    cin >> S;

    // Check if the input seconds are less than 60
    if (S < 60) {
        // If less than 60 seconds, print the time in the format 0:0:seconds
        cout << "0:0:" << S << endl;
    }
    // Check if the input seconds are less than 3600 (1 hour)
    else if (S < 3600) {
        // If less than 1 hour, print the time in the format 0:minutes:seconds
        cout << "0:" << (int)S / 60 << ":" << S % 60 << endl;
    }
    // If the input seconds are 3600 or more (1 hour or more)
    else {
        // Print the time in the format hours:minutes:seconds
        cout << (int)S / 3600 << ":" << (int)(S % 3600) / 60 << ":" << S % 60 << endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}
