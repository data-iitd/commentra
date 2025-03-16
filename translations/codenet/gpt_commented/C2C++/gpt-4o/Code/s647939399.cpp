#include <iostream>
#include <vector>

int main() {
    char m; // Variable to store the operator
    int a, b; // Variables for operands
    std::vector<int> c; // Vector to store results

    // Infinite loop to continuously read input until a termination condition is met
    while (true) {
        // Read two integers and an operator from the user
        std::cin >> a >> m >> b;

        // Check if the operator is '?' to terminate the loop
        if (m == '?') {
            break; // Exit the loop if the termination operator is encountered
        }

        // Perform addition if the operator is '+'
        if (m == '+') {
            c.push_back(a + b); // Store the result of addition in the results vector
        }

        // Perform subtraction if the operator is '-'
        if (m == '-') {
            c.push_back(a - b); // Store the result of subtraction in the results vector
        }

        // Perform multiplication if the operator is '*'
        if (m == '*') {
            c.push_back(a * b); // Store the result of multiplication in the results vector
        }

        // Perform division if the operator is '/'
        if (m == '/') {
            c.push_back(a / b); // Store the result of division in the results vector
        }
    }

    // Print all results stored in the results vector
    for (const auto& result : c) {
        std::cout << result << std::endl; // Output each result on a new line
    }

    return 0; // Return success
}

// <END-OF-CODE>
