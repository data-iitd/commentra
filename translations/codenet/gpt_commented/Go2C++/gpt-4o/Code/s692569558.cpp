#include <iostream> // For input and output
#include <vector>  // For using vectors
#include <sstream> // For string stream
#include <string>  // For string manipulation

int main() {
    // Read the first line of input (not used)
    std::string line;
    std::getline(std::cin, line);
    
    // Read the second line of input which contains space-separated integers
    std::getline(std::cin, line);
    
    // Create a string stream from the input line
    std::istringstream iss(line);
    std::vector<int> dn; // Vector to hold the converted values
    int number;

    // Convert each space-separated string to an integer
    while (iss >> number) {
        dn.push_back(number);
    }

    // Initialize a variable to hold the sum of products
    int sum = 0;
    // Calculate the sum of products of all unique pairs of integers
    for (size_t i = 0; i < dn.size(); i++) {
        for (size_t j = i + 1; j < dn.size(); j++) {
            sum += dn[i] * dn[j]; // Multiply the pair and add to sum
        }
    }

    // Output the final sum of products
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
