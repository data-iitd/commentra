#include <iostream>
#include <string>
#include <vector>

// Define a function named 'generateString' that returns a vector of characters
// representing a string of numbers from 1 to 1000
std::vector<char> generateString() {
    std::string s; // Create an empty string

    // Use a for loop to append numbers from 1 to 1000 to the string
    for (int i = 1; i <= 1000; i++) {
        s += std::to_string(i); // Append the current number to the string
    }

    // Convert the string to a vector of characters and return it
    std::vector<char> charVector(s.begin(), s.end());
    return charVector;
}

// Define the main function that reads user input and prints the result
int main() {
    int n; // Declare an integer variable to store user input

    // Read an integer value from the standard input
    std::cin >> n;

    // Get the generated string as a vector of characters
    std::vector<char> generatedString = generateString();

    // Print the character at the specified index of the generated string
    std::cout << generatedString[n - 1] << std::endl;

    return 0;
}
