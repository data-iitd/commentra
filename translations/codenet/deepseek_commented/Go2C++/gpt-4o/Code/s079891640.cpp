#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s; // Variable to store the input string
    std::cin >> s; // Read the input string from standard input

    std::unordered_set<char> seen; // Set to keep track of seen characters

    for (char c : s) { // Iterate over each character in the string
        if (seen.find(c) != seen.end()) { // Check if the character has been seen before
            std::cout << "no" << std::endl; // If it has, print "no" and exit
            return 0;
        }
        seen.insert(c); // Insert the character into the set
    }

    std::cout << "yes" << std::endl; // If no character appears again, print "yes"
    return 0;
}

// <END-OF-CODE>
