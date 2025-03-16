#include <iostream>
#include <vector>
#include <string>

int main() {
    int firstline;
    std::cin >> firstline;  // Read the first line of input, which determines the number of iterations
    int total = 0;  // Initialize a variable to keep track of the total sum
    std::vector<char> memory;  // Initialize a vector to store the decisions

    // Loop through the range of firstline
    for (int x = 0; x < firstline; x++) {
        int A, G;
        std::cin >> A >> G;  // Read two integers from a single line of input
        if (total + A <= 500) {  // Check if adding A to total would not exceed 500
            total += A;  // Add A to total
            memory.push_back('A');  // Append 'A' to memory
        } else {
            total -= G;  // Subtract G from total
            memory.push_back('G');  // Append 'G' to memory
        }
    }

    // Join the elements of memory into a single string and print it
    for (char decision : memory) {
        std::cout << decision;  // Print each decision
    }
    std::cout << std::endl;  // Print a newline at the end

    return 0;
}

// <END-OF-CODE>
