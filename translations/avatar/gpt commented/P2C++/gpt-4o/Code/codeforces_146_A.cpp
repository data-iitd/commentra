#include <iostream>
#include <vector>

int main() {
    // Read an integer input which represents the number of elements
    int n;
    std::cin >> n;

    // Read a list of integers from input and store them in a vector
    std::vector<int> number(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> number[i];
    }

    // Initialize two variables to hold the sums of the two halves
    int h1 = 0;  // Sum of the first half
    int h2 = 0;  // Sum of the second half
    bool valid = true; // Flag to check if all numbers are 4 or 7

    // Iterate through the list of numbers
    for (int i = 0; i < n; ++i) {
        // Check if the current number is neither 4 nor 7
        if (number[i] != 4 && number[i] != 7) {
            std::cout << "NO" << std::endl; // Print "NO" if an invalid number is found
            valid = false; // Set the flag to indicate an invalid number was found
            break; // Exit the loop since we found an invalid number
        }

        // Sum the first half of the numbers
        if (i < n / 2) {
            h1 += number[i];
        } else {
            // Sum the second half of the numbers
            h2 += number[i];
        }
    }

    // After checking all numbers, determine if the sums of both halves are equal
    if (valid) { // Proceed only if no invalid numbers were found
        if (h1 == h2) {
            std::cout << "YES" << std::endl; // Print "YES" if the sums are equal
        } else {
            std::cout << "NO" << std::endl; // Print "NO" if the sums are not equal
        }
    }

    return 0;
}

// <END-OF-CODE>
