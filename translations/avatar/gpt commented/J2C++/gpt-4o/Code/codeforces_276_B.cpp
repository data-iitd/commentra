#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Initialize input stream to read from standard input
    std::string str;
    std::getline(std::cin, str); // Read a line of input from the user

    // Create a map to count occurrences of each character
    std::unordered_map<char, int> map;
    int oddCount = 0; // Initialize counter for characters with odd occurrences

    // Iterate through each character in the input string
    for (char ch : str) {
        // Update the count of the character in the map
        map[ch]++;
    }

    // Count how many characters have an odd number of occurrences
    for (const auto& entry : map) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    // Determine the output based on the count of odd occurrences
    if (oddCount <= 1 || oddCount % 2 != 0) {
        std::cout << "First" << std::endl; // Output "First" if conditions are met
    } else {
        std::cout << "Second" << std::endl; // Output "Second" otherwise
    }

    return 0; // End of the program
}

// <END-OF-CODE>
