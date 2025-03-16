// Include necessary headers
#include <iostream> // For input and output
#include <string>   // For string manipulation
#include <vector>   // For using vectors

// Main function
int main() {
    // Read the first string from standard input
    std::string s;
    std::cin >> s;

    // Initialize variable c with 'a'
    char c = 'a';

    // Check all characters from 'a' to 'z' in the string s
    for (int j = 0; j < 26; j++) {
        // Initialize variable found as false
        bool found = false;

        // Iterate through each character in the string s
        for (size_t i = 0; i < s.length(); i++) {
            // If current character matches c, set found to true and break the loop
            if (s[i] == c) {
                found = true;
                break;
            }
        }

        // If character c is not found in the string s, print it and return
        if (!found) {
            std::cout << c << std::endl;
            return 0;
        }

        // Increment variable c
        c++;
    }

    // If no character from 'a' to 'z' is found in the string s, print "None"
    std::cout << "None" << std::endl;

    return 0;
}
// <END-OF-CODE>
