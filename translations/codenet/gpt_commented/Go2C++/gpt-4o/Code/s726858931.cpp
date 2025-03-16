#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    // Read the input string
    std::string s;
    std::cin >> s;

    // Use a set to track the characters present in the input string
    std::unordered_set<char> charSet(s.begin(), s.end());

    // Start checking for the first missing lowercase letter from 'a'
    for (char c = 'a'; c <= 'z'; ++c) {
        // If the current letter is not found in the set, print it and exit
        if (charSet.find(c) == charSet.end()) {
            std::cout << c << std::endl;
            return 0;
        }
    }

    // If all letters from 'a' to 'z' are found, print "None"
    std::cout << "None" << std::endl;

    return 0;
}

// <END-OF-CODE>
