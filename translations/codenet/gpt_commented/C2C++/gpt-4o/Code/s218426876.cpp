#include <iostream>
#include <cstring>

int main() {
    // Declare variables for iteration and sum
    int sum = 0;
    char x[1002]; // Array to store input strings

    // Read the first input string
    std::cin >> x;

    // Loop to process input until the termination condition is met
    do {
        // Iterate through the characters of the input string
        for (int i = 0; i < 1002; i++) {
            // Check for the end of the string (null character)
            if (x[i] == '\0') {
                // Print the sum of the digits in the string
                std::cout << sum << std::endl;
                break; // Exit the loop if end of string is reached
            } else {
                // Convert character to integer and add to sum
                sum += x[i] - '0'; // '0' is represented by '0' in C++
            }
        }
        
        // Reset sum for the next input
        sum = 0;

        // Read the next input string
        std::cin >> x;
    } while (x[0] != '0'); // Continue until the first character is '0'

    return 0; // Exit the program
} // <END-OF-CODE>
