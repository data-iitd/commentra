#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // Initialize an empty vector to store the sequence
    std::vector<int> L;

    // Read input (not used, but could be for prompting the user)
    std::string temp;
    std::getline(std::cin, temp);

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    std::getline(std::cin, temp);
    std::istringstream iss(temp);
    std::string k;
    while (iss >> k) {
        // Extend the vector 'L' by adding 'r' for 'stoi(k)' times
        int count = std::stoi(k);
        for (int i = 0; i < count; ++i) {
            L.push_back(r);
        }
        // Increment 'r' for the next number
        r++;
    }

    // Read another line of input (not used, but could be for prompting the user)
    std::getline(std::cin, temp);

    // Read a line of input, split it into parts, and iterate over each part
    std::getline(std::cin, temp);
    std::istringstream iss2(temp);
    std::string j;
    while (iss2 >> j) {
        // Print the element from vector 'L' at the index specified by 'j' (adjusted for 0-based index)
        std::cout << L[std::stoi(j) - 1] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
