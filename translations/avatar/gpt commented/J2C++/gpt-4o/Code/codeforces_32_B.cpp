#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std;

int main() {
    // Creating a string variable to read input from the console
    string input;
    cin >> input; // Reading input

    // Initializing a boolean variable to track the state of the previous character
    bool s = false;

    // Iterating through each character in the input string
    for (size_t i = 0; i < input.length(); i++) {
        // Checking if the current character is a dot '.'
        if (input[i] == '.') {
            // If the previous character was also a dot, print 1 and reset the state
            if (s) {
                cout << 1;
                s = false; // Resetting the state
            } else {
                // If the previous character was not a dot, print 0
                cout << 0;
            }
        } else {
            // If the current character is not a dot
            if (s) {
                // If the previous character was also not a dot, print 2 and reset the state
                cout << 2;
                s = false; // Resetting the state
            } else {
                // If the previous character was a dot, set the state to true
                s = true;
            }
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
