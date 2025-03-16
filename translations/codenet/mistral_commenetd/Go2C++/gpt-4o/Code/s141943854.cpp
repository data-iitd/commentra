#include <iostream>
#include <string>

void check(bool condition, const std::string& message) {
    if (condition) {
        std::cerr << "error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    std::string sage;
    
    // Read the first line from standard input
    std::getline(std::cin, sage);

    // Use a switch statement to determine the action based on the first line read
    if (sage == "1") {
        // Print "Hello World" if the first line is "1"
        std::cout << "Hello World" << std::endl;
    } else if (sage == "2") {
        // Initialize a variable named 'sum' to store the sum of two numbers
        int sum = 0;

        // Use a for loop to read and sum two numbers
        for (int i = 0; i < 2; i++) {
            std::string input;
            // Read the next line from standard input
            std::getline(std::cin, input);

            // Convert the next line to an integer and store it in a variable named 'num'
            int num = std::stoi(input);
            // Check for errors (in this case, we assume input is valid as per the original Go code)
            // Add the current number to the sum
            sum += num;
        }

        // Print the sum of the two numbers
        std::cout << sum << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
