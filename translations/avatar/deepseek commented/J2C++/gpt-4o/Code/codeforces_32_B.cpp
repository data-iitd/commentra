#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulation

int main() {
    std::string input; // Declare a string to hold the input
    std::cin >> input; // Read the input string from the user
    bool s = false;    // Initialize a boolean variable to keep track of the state

    // Process each character in the input string
    for (char c : input) {
        if (c == '.') { // Check if the current character is a dot
            if (s) { // If the state is true
                std::cout << 1; // Print '1' and reset the state to false
                s = false;
            } else { // If the state is false
                std::cout << 0; // Print '0' and set the state to false
                s = false;
            }
        } else { // If the current character is not a dot
            if (s) { // If the state is true
                std::cout << 2; // Print '2' and reset the state to false
                s = false;
            } else { // If the state is false
                s = true; // Set the state to true
            }
        }
    }
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
