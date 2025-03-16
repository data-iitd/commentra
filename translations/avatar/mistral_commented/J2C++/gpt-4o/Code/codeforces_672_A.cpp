// Include the necessary header files for input/output and string manipulation
#include <iostream>
#include <string>

// Define a function named 'generateString' that returns a string
std::string generateString() {
    std::string result; // Create a string to hold the numbers

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 1; i <= 1000; i++) {
        result += std::to_string(i); // Append the current number to the string
    }

    // Return the generated string
    return result;
}

// Define the main function that reads user input and prints the result
int main() {
    int n; // Declare an integer variable to hold user input

    std::cin >> n; // Read an integer value from the user input

    // Print the character at the specified index of the generated string
    std::cout << generateString()[n - 1] << std::endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
