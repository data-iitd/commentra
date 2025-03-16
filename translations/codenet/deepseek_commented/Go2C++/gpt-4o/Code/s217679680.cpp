#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input); // Read a line of input

    std::istringstream iss(input);
    int a, b;
    iss >> a >> b; // Extract the two integers from the input

    int tap = 0; // Initialize the tap counter
    int consent = 1; // Initialize the consent level

    while (consent < b) { // Loop until consent reaches or exceeds b
        consent += a - 1; // Increment consent by a - 1
        tap++; // Increment the tap counter
    }

    std::cout << tap << std::endl; // Print the number of taps needed
    return 0;
}

// <END-OF-CODE>
