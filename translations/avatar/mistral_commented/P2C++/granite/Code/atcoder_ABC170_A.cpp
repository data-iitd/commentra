

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read a list of space-separated integers as input from the standard input
    // and store them in a vector of integers using the std::vector and std::istringstream classes
    std::vector<int> a;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int value;
    while (iss >> value) {
        a.push_back(value);
    }

    // Iterate over the elements of the vector a using the std::for_each function
    // which applies a given function object to each element of the vector
    std::for_each(a.begin(), a.end(), [](int value) {
        // Check if the current value is equal to zero
        if (value == 0) {
            // Print the index of the first zero to the standard output
            std::cout << std::distance(a.begin(), it) + 1 << std::endl;
            // Terminate the loop using the return statement
            return;
        }
    });

    return 0;
}

