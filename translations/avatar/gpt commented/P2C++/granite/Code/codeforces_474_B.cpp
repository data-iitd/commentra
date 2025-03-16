
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Initialize an empty vector to store the sequence
    std::vector<int> L;

    // Read input (not used, but could be for prompting the user)
    std::string ignore;
    std::cin >> ignore;

    // Initialize a variable 'r' to keep track of the current number to be added to the vector
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    std::string line;
    std::getline(std::cin, line);
    for (const auto& k : line) {
        // Extend the vector 'L' by adding 'r' for 'k' times
        L.insert(L.end(), k - '0', r);
        // Increment 'r' for the next number
        r += 1;
    }

    // Read another line of input (not used, but could be for prompting the user)
    std::cin >> ignore;

    // Read a line of input, split it into parts, and iterate over each part
    std::getline(std::cin, line);
    for (const auto& j : line) {
        // Print the element from vector 'L' at the index specified by 'j' (adjusted for 0-based index)
        std::cout << L[j - '1'] << std::endl;
    }

    return 0;
}
