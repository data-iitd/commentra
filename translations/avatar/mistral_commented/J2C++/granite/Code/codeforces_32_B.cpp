
#include <iostream> // Including the iostream library for input and output operations
#include <string> // Including the string library for string manipulation

using namespace std; // Using the standard namespace for the iostream library

int main() { // Starting the main function
    string n; // Declaring a string variable 'n' to store the input string
    getline(cin, n); // Reading a string from the console and storing it in the string variable 'n'

    bool s = false; // Declaring a boolean variable's' and initializing it to false

    for (int i = 0; i < n.length(); i++) { // Starting a for loop to iterate through each character in the string variable 'n'
        if (n[i] == '.') { // Checking if the current character is a '.'
            if (s) { // If the boolean variable's' is true
                cout << 1; // Printing '1' to the console
                s = false; // Setting the boolean variable's' to false
            } else { // If the boolean variable's' is false
                cout << 0; // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if (s) { // If the boolean variable's' is true
                cout << 2; // Printing '2' to the console
                s = false; // Setting the boolean variable's' to false
            } else { // If the boolean variable's' is false
                s = true; // Setting the boolean variable's' to true
            }
        }
    }

    return 0; // Returning 0 to indicate successful execution of the program
}

