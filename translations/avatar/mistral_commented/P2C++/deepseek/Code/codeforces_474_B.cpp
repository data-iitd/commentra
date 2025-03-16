#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Initialize an empty vector `L`
    std::vector<int> L;

    // Read the first input, which is the number of elements to add to the list
    std::string input;
    std::getline(std::cin, input);

    // Use a for loop to iterate through each integer in the input
    std::istringstream iss(input);
    int r = 1;
    for (std::string k; iss >> k;) {
        // Add `r` elements to the vector `L` with the value `r`
        for (int i = 0; i < r; ++i) {
            L.push_back(r);
        }
        // Increment the value of `r` by 1 to prepare for the next iteration
        ++r;
    }

    // Read the second input, which represents the indices of the elements to print from the list
    std::getline(std::cin, input);

    // Use another for loop to iterate through each integer in the input
    std::istringstream iss2(input);
    for (std::string j; iss2 >> j;) {
        // Print the element at the given index using the index as an offset from the beginning of the list
        std::cout << L[std::stoi(j) - 1] << std::endl;
    }

    return 0;
}

