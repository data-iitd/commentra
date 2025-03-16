#include <iostream>
#include <string>

void check(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Read the first line of input.
    std::string sage;
    std::getline(std::cin, sage); // Store the input in the variable 'sage'.

    // Use a switch statement to handle different cases based on the input value.
    if (sage == "1") {
        // If the input is "1", print "Hello World".
        std::cout << "Hello World" << std::endl;
    } else if (sage == "2") {
        // If the input is "2", initialize a variable to hold the sum of two numbers.
        int sum = 0;
        // Loop to read two numbers from input.
        for (int i = 0; i < 2; i++) {
            std::string input;
            std::getline(std::cin, input); // Read the next line of input.
            int num = std::stoi(input); // Convert the input string to an integer.
            sum += num; // Add the number to the sum.
        }
        // Print the total sum of the two numbers.
        std::cout << sum << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
