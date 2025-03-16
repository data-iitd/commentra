#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Declare a variable to hold the input string
    std::string s;
    // Read input from the user
    std::getline(std::cin, s);

    // Initialize a counter for consecutive valid characters and a vector to hold counts
    int count = 0;
    std::vector<int> counter;

    // If the input string is empty, exit the function
    if (s.empty()) {
        return 0;
    }

    // Start the counter with an initial value of 0
    counter.push_back(0);

    // Iterate over each character in the string
    for (char c : s) {
        // Check if the character is one of the valid DNA bases
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            // Increment the count for consecutive valid characters
            count++;
        } else {
            // If an invalid character is encountered, store the current count
            counter.push_back(count);
            // Reset the count for the next sequence
            count = 0;
        }
    }

    // Append the count of the last sequence of valid characters
    counter.push_back(count);
    // Sort the counts to find the maximum consecutive valid characters
    std::sort(counter.begin(), counter.end());
    // Print the maximum count of consecutive valid characters
    std::cout << counter.back() << std::endl;

    return 0;
}
