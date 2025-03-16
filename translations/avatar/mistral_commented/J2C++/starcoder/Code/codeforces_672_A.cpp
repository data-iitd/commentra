// Import the C++ utility library for string manipulation and input/output
#include <iostream>
#include <string>

// Define a static method named 'generateString' that returns a string
// representing a string of numbers from 1 to 1000
std::string generateString() {
    std::string result; // Create a string object

    // Use a for loop to append numbers from 1 to 1000 to the string object
    for (int i = 1; i <= 1000; i++) {
        result += std::to_string(i); // Append the current number to the string object
    }

    // Return the string object
    return result;
}

// Define the main method that reads user input and prints the result
int main() {
    std::string input; // Create a string object to read user input

    // Read an integer value from the user input
    std::cin >> input;

    // Print the character at the specified index of the generated string
    std::cout << generateString()[std::stoi(input) - 1];

    return 0;
}

