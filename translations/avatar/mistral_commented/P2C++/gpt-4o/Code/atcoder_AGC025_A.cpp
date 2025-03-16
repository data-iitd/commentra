#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // Take an input from the user and assign it to the variable 'n'
    std::string n;
    std::cin >> n;

    // Initialize a vector 'a' with some strings representing numbers
    std::vector<std::string> a = { "10", "100", "1000", "10000", "100000" };

    // Convert each character of the input 'n' to an integer and sum them up
    int newSum = 0;
    for (char c : n) {
        newSum += c - '0'; // Convert char to int
    }

    // Check if the input 'n' is present in the vector 'a'
    bool found = false;
    for (const std::string& str : a) {
        if (n == str) {
            found = true;
            break;
        }
    }

    // If the input 'n' is present in the vector 'a', then print the number 10
    if (found) {
        std::cout << 10 << std::endl;
    } else {
        // If the input 'n' is not present in the vector 'a', then print the value of the variable 'newSum'
        std::cout << newSum << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
