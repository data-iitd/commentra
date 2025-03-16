
#include <iostream> // Importing the iostream library for input/output operations
#include <string> // Importing the string library for string manipulation

using namespace std; // Using the standard namespace for convenience

int main() {
    // Creating a string variable to store the input string
    string n;
    
    // Reading a string input from the console and storing it in the string variable
    getline(cin, n);
    
    // Initializing a boolean variable to track the state of the previous character
    bool s = false;
    
    // Iterating through each character in the string
    for (int i = 0; i < n.length(); i++) {
        // Checking if the current character is a dot '.'
        if (n[i] == '.') {
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
    
    // Ending the program with a comment "