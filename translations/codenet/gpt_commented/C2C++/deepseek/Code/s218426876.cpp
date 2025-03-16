#include <iostream>
#include <string>

int main() {
    // Declare variables for iteration, sum, and a flag
    int i, sum = 0;
    std::string x; // Use std::string to store input strings

    // Loop to process input until the termination condition is met
    while (true) {
        // Read the next input string
        std::cin >> x;

        // Check for the termination condition
        if (x[0] == '0') {
            break; // Exit the loop if the first character is '0'
        }

        // Iterate through the characters of the input string
        for (i = 0; i < x.length(); i++) {
            // Convert character to integer and add to sum
            sum += x[i] - '0'; // '0' is represented by '0' in ASCII
        }

        // Print the sum of the digits in the string
        std::cout << sum << std::endl;

        // Reset sum for the next input
        sum = 0;
    }

    return 0; // Exit the program
}
