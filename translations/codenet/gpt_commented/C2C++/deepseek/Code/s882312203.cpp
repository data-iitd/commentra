#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    // Declare a string to hold the input string
    std::string s;

    // Read a string from standard input
    std::cin >> s;

    // Loop through each character in the string
    for (size_t j = 0; j < s.length(); j++) {
        // Compare the current character with every other character in the string
        for (size_t i = 0; i < s.length(); i++) {
            // Check if the characters are the same and they are not the same position
            if ((i != j) && (s[i] == s[j])) {
                // If a duplicate character is found, print "no" and exit the program
                std::cout << "no" << std::endl;
                return 0;
            }
        }
    }

    // If no duplicates were found, print "yes"
    std::cout << "yes" << std::endl;

    return 0;
}
