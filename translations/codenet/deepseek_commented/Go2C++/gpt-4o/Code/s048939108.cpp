#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Main function starts here
int main() {
    // Initialize a string to read input
    std::string S;
    // Read the next string from standard input
    std::getline(std::cin, S);
    // Check if the string S starts with the prefix "YAKI"
    if (S.rfind("YAKI", 0) == 0) {
        // If it does, print "Yes"
        std::cout << "Yes" << std::endl;
    } else {
        // Otherwise, print "No"
        std::cout << "No" << std::endl;
    }
    return 0; // Return success
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to read the next integer from the input
int nextInt() {
    int v;
    std::cin >> v;
    return v;
}

// Function to read the next array of integers from the input
std::vector<int> nextIntArray() {
    std::vector<int> result;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        result.push_back(number);
    }
    return result;
}

// Function to read a line from the input
std::string nextLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

// Function to preprocess input (not needed in C++ as we read line by line)
void pre() {
    // No preprocessing needed in this implementation
}

// <END-OF-CODE>
