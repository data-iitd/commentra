
// Include the C++ utility library for string manipulation and input/output
#include <iostream>
#include <string>

// Define a function named 'generateString' that returns a string representing a string of numbers from 1 to 1000
std::string generateString() {
    std::string result; // Create a string object to store the generated string

    // Use a for loop to append numbers from 1 to 1000 to the string object
    for (int i = 1; i <= 1000; i++) {
        result += std::to_string(i); // Append the current number to the string object
    }

    // Return the generated string
    return result;
}

// Define the main function that reads user input and prints the result
int main() {
    std::cin.tie(nullptr); // Disable input buffering
    std::ios::sync_with_stdio(false); // Disable C++ stream synchronization with C stream I/O

    int n; // Declare an integer variable to store the user input

    // Read an integer value from the user input
    std::cin >> n;

    // Print the character at the specified index of the generated string
    std::cout << generateString()[n - 1] << '\n'; // Print the character at the specified index of the generated string

    return 0;
}

