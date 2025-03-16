#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s; // Declare a variable to hold the input string
    std::cin >> s; // Read input from the user and store it in the variable 's'

    std::unordered_set<char> seen; // Create a set to track seen characters

    // Iterate over each character in the string 's'
    for (char c : s) {
        // Check if the current character has already been seen
        if (seen.find(c) != seen.end()) {
            // If the character is found in the set, print "no" and exit
            std::cout << "no" << std::endl;
            return 0;
        }
        // Add the current character to the set
        seen.insert(c);
    }

    // If no duplicate characters were found, print "yes"
    std::cout << "yes" << std::endl;

    return 0;
}

// <END-OF-CODE>
