// Importing necessary C++ libraries
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Main function is the entry point of the C++ application
int main() {
    try {
        // Creating a string to hold the input
        string input;
        
        // Reading a line of input from the console
        getline(cin, input);
        
        // Creating a string stream to parse the input
        stringstream ss(input);
        
        // Declaring variables to hold the parsed integers
        int a, b;
        
        // Reading the first and second integers from the input
        ss >> a >> b;

        // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
        int c = a - b * 2;

        // If the value of 'c' is negative, set it to zero
        if (c < 0) {
            c = 0;
        }

        // Print the value of 'c' to the console
        cout << c << endl;
    } catch (...) {
        // Handling any exceptions that might occur during the execution of the program
    }

    return 0;
}

// <END-OF-CODE>
