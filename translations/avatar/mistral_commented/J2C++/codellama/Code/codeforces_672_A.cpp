// Include the iostream library for input/output
#include <iostream>

// Include the string library for string manipulation
#include <string>

// Define a function named 'generateString' that returns a string of numbers from 1 to 1000
std::string generateString() {
    std::string str = ""; // Create an empty string

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 1; i <= 1000; i++) {
        str += std::to_string(i); // Append the current number to the string
    }

    // Return the string
    return str;
}

// Define the main function that reads user input and prints the result
int main() {
    int n; // Declare an integer variable to store the user input

    // Read an integer value from the user input
    std::cin >> n;

    // Print the character at the specified index of the generated string
    std::cout << generateString()[n - 1] << std::endl;

    return 0;
}

