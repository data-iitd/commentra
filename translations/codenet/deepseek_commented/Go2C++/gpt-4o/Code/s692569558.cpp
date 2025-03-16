#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Create a string to hold the input
    std::string line;

    // Read the first line of input (which we will ignore)
    std::getline(std::cin, line);

    // Read the second line of input
    std::getline(std::cin, line);
    
    // Split the input string into a vector of strings
    std::istringstream iss(line);
    std::vector<int> dn;
    int number;

    // Convert each string in the stream to an integer
    while (iss >> number) {
        dn.push_back(number);
    }

    // Initialize the sum variable to hold the result
    int sum = 0;

    // Calculate the sum of the products of all pairs of integers in the vector
    for (size_t i = 0; i < dn.size(); i++) {
        for (size_t j = i + 1; j < dn.size(); j++) {
            sum += dn[i] * dn[j];
        }
    }

    // Print the result
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
