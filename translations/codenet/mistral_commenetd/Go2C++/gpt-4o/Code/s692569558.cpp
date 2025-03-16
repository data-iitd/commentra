#include <iostream> // Include iostream for input and output
#include <vector>   // Include vector for dynamic array
#include <sstream>  // Include sstream for string stream
#include <string>   // Include string for string manipulation

int main() {
    // Initialize a string to hold the input line
    std::string line;

    // Read the first two lines from standard input
    std::getline(std::cin, line); // Read first line (not used)
    std::getline(std::cin, line); // Read second line

    // Create a string stream from the line to split it into integers
    std::istringstream iss(line);
    std::vector<int> dn; // Vector to hold the integers

    // Variable to hold each number as we read from the stream
    int number;
    while (iss >> number) {
        dn.push_back(number); // Add the number to the vector
    }

    // Initialize sum variable to 0
    int sum = 0;

    // Iterate through each index i in the vector dn
    for (size_t i = 0; i < dn.size(); i++) {
        // Iterate through each index j greater than i in the vector dn
        for (size_t j = i + 1; j < dn.size(); j++) {
            // Add the product of dn[i] and dn[j] to the sum variable
            sum += dn[i] * dn[j];
        }
    }

    // Print the value of sum variable to the standard output
    std::cout << sum << std::endl;

    // End of code
    return 0;
}
