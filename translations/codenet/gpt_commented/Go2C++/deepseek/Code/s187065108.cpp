#include <iostream>
#include <string>
#include <sstream>

// Function to read an integer from input
int readInt() {
    int num;
    std::cin >> num;
    return num;
}

// Function to read a string from input
std::string readString() {
    std::string str;
    std::cin >> str;
    return str;
}

// Main function is the entry point of the program
int main() {
    // Read three integers from input: r, D, and x
    int r = readInt();
    int D = readInt();
    int x = readInt();
    
    // Perform calculations and print the result for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r * x - D; // Update x based on the formula
        std::cout << x << std::endl; // Print the current value of x
    }
    
    return 0;
}
