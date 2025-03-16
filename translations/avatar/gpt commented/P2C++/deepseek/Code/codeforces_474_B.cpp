#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // Initialize an empty vector to store the sequence
    std::vector<int> L;

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string part;
    while (iss >> part) {
        // Extend the vector 'L' by adding 'r' for 'stoi(part)' times
        for (int i = 0; i < std::stoi(part); ++i) {
            L.push_back(r);
        }
        // Increment 'r' for the next number
        ++r;
    }

    // Read another line of input (not used, but could be for prompting the user)
    std::getline(std::cin, line);

    // Read a line of input, split it into parts, and iterate over each part
    std::getline(std::cin, line);
    std::istringstream iss2(line);
    while (iss2 >> part) {
        // Print the element from vector 'L' at the index specified by 'part' (adjusted for 0-based index)
        std::cout << L[std::stoi(part) - 1] << std::endl;
    }

    return 0;
}
