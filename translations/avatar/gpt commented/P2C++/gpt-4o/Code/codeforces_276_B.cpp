#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    // Read input and convert it to a vector of characters
    std::string input;
    std::cin >> input;
    std::vector<char> s(input.begin(), input.end());

    // Initialize a flag variable and a map to count occurrences of each character
    bool x = true;
    std::unordered_map<char, int> dt;

    // Count the occurrences of each character in the input vector
    for (char i : s) {
        dt[i]++;  // Increment the count for the character
    }

    // Initialize a counter for odd occurrences
    int cnt = 0;

    // Check the counts of each character to determine the number of odd occurrences
    for (const auto& pair : dt) {
        if (pair.second % 2 != 0) {
            if (cnt < 1) {
                cnt++;  // Count the first odd occurrence
            } else {
                x = false;  // More than one odd occurrence found, set flag to false
                break;
            }
        }
    }

    // Determine the output based on the number of odd occurrences and the length of the input
    if (x) {
        std::cout << "First" << std::endl;  // If there are no more than one odd occurrences, print "First"
    } else if (!x && s.size() % 2 == 0) {
        std::cout << "Second" << std::endl;  // If there are more than one odd occurrences and the length is even, print "Second"
    } else if (!x && s.size() % 2 != 0) {
        std::cout << "First" << std::endl;  // If there are more than one odd occurrences and the length is odd, print "First"
    }

    return 0;
}

// <END-OF-CODE>
