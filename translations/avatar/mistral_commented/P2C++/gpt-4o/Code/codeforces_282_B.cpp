#include <iostream>
#include <vector>
#include <string>

int main() {
    // Take the first line as an input
    int firstline;
    std::cin >> firstline;

    // Initialize total and memory vector
    int total = 0;
    std::vector<char> memory;

    // Loop through the given number of lines
    for (int x = 0; x < firstline; x++) {
        // Take two integers as input, A and G
        int A, G;
        std::cin >> A >> G;

        // Check if adding A to the total memory usage is within the limit
        if (total + A <= 500) {
            // If yes, add A to the total and append 'A' to the memory vector
            total += A;
            memory.push_back('A');
        } else {
            // If no, subtract G from the total and append 'G' to the memory vector
            total -= G;
            memory.push_back('G');
        }
    }

    // Print the final memory state
    for (char c : memory) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
