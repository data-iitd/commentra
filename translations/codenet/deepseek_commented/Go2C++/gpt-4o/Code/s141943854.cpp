#include <iostream> // For input and output
#include <string>   // For string operations
#include <stdexcept> // For exception handling

// Function to check for errors and throw exceptions
void check(bool condition, const std::string& message) {
    if (condition) {
        throw std::runtime_error(message);
    }
}

int main() {
    std::string sage;
    std::getline(std::cin, sage); // Read input from standard input

    if (sage == "1") {
        std::cout << "Hello World" << std::endl; // Print "Hello World" if input is "1"
    } else if (sage == "2") {
        int sum = 0; // Declare sum variable to store the sum of two integers
        for (int i = 0; i < 2; i++) {
            std::string input;
            std::getline(std::cin, input); // Read input from standard input
            int num = std::stoi(input); // Convert string to integer
            check(false, "Invalid input"); // Check for errors during conversion (not needed here as stoi will throw)
            sum += num; // Add the integer to the sum
        }
        std::cout << sum << std::endl; // Print the sum of the two integers
    }

    return 0;
}

// <END-OF-CODE>
