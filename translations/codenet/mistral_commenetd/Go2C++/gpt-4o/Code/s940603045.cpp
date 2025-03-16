// Include necessary headers
#include <iostream> // For input and output
#include <vector>  // For using vectors
#include <string>  // For using strings
#include <algorithm> // For using algorithms like min and max
#include <cstdlib> // For atoi
#include <ctime>   // For seeding random number generator
#include <limits>  // For numeric limits

// Constants and variables declaration
const int inf = std::numeric_limits<int>::max(); // Maximum signed integer value

// Directions for movement
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Function to read a string from input
std::string readString() {
    std::string input;
    std::cin >> input; // Read input as a string
    return input;
}

// Function to calculate the sum of digits in a string
int sumOfDigits(const std::string& str) {
    int sum = 0;
    for (char c : str) {
        sum += c - '0'; // Convert each character to an integer and add to the sum
    }
    return sum;
}

// Main function
int main() {
    std::srand(std::time(0)); // Seed random number generator with current time

    // Read input N as a string
    std::string N = readString();
    
    // Calculate the sum of digits
    int n = sumOfDigits(N);
    
    // Convert N to an integer
    int m = std::atoi(N.c_str());
    
    // Check if m is divisible by n
    if (n != 0 && m % n == 0) {
        std::cout << "Yes" << std::endl; // Print "Yes" if m is divisible by n
    } else {
        std::cout << "No" << std::endl; // Print "No" if m is not divisible by n
    }

    return 0; // Return success
}

// <END-OF-CODE>
