#include <iostream>
#include <string>
#include <algorithm> // For std::min

// Function to return the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y; // Return the smaller of x and y
}

// Main function where the program execution begins
int main() {
    std::string S; // Declare a string to hold the input
    std::cin >> S; // Read the input string

    int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
    // Loop through each character in the input string
    for (char c : S) {
        if (c == '0') {
            l0++; // Increment the counter for '0'
        } else {
            l1++; // Increment the counter for '1'
        }
    }
    // Print the result, which is twice the minimum count of '0's or '1's
    std::cout << 2 * min(l0, l1) << std::endl;

    return 0; // Indicate successful completion
}

// <END-OF-CODE>
