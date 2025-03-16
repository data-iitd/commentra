#include <iostream>
#include <vector>
#include <string>

int main() {
    // Read the first line of input which indicates the number of iterations
    int firstline;
    std::cin >> firstline;

    // Initialize total to keep track of the accumulated value
    int total = 0;

    // Create a string to store the memory of actions taken
    std::string memory;

    // Loop through the range defined by firstline
    for (int x = 0; x < firstline; x++) {
        // Read two integers A and G from input, separated by space
        int A, G;
        std::cin >> A >> G;

        // Check if adding A to total does not exceed the limit of 500
        if (total + A <= 500) {
            // If within limit, add A to total
            total += A;
            // Record the action "A" in memory
            memory += "A";
        } else {
            // If limit exceeded, subtract G from total
            total -= G;
            // Record the action "G" in memory
            memory += "G";
        }
    }

    // Print the sequence of actions taken as a single string
    std::cout << memory << std::endl;

    return 0;
}

// <END-OF-CODE>
