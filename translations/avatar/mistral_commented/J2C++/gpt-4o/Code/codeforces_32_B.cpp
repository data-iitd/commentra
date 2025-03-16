#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    string input; // Declaring a string variable to hold the input
    cin >> input; // Reading a string from the console

    bool s = false; // Initializing a boolean variable 's' to false

    for (char c : input) { // Starting a for loop to iterate through each character in the input string
        if (c == '.') { // Checking if the current character is a '.'
            if (s) { // If the boolean variable 's' is true
                cout << 1; // Printing '1' to the console
                s = false; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                cout << 0; // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if (s) { // If the boolean variable 's' is true
                cout << 2; // Printing '2' to the console
                s = false; // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                s = true; // Setting the boolean variable 's' to true
            }
        }
    }

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
