#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> L; // Initialize an empty vector L to store the results.
    std::string input; // Variable to store user input.

    std::getline(std::cin, input); // Take the first input from the user.
    int r = 1; // Initialize the variable r to 1.

    std::istringstream iss(input);
    std::string k;
    while (iss >> k) { // Split the first input into a list of strings and iterate over each string.
        int count = std::stoi(k); // Convert the string to an integer.
        for (int i = 0; i < count; ++i) {
            L.push_back(r); // Append the result to the vector L.
        }
        r++; // Increment r by 1 for the next iteration.
    }

    std::getline(std::cin, input); // Take the second input from the user.
    std::istringstream iss2(input);
    std::string j;
    while (iss2 >> j) { // Split the second input into a list of strings and iterate over each string.
        std::cout << L[std::stoi(j) - 1] << std::endl; // Print the element at the specified index from the vector L.
    }

    return 0;
}
// <END-OF-CODE>
