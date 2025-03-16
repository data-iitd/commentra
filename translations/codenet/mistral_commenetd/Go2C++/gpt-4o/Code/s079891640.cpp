#include <iostream>
#include <string>

int main() {
    // Declare a variable named 's' of type string
    std::string s;

    // Read a string input from the standard input
    std::cin >> s;

    // Initialize a for loop to iterate through each character in the string 's'
    for (size_t i = 0; i < s.length(); i++) {
        // Check if the character at index 'i+1' in the string 's' contains the character at index 'i'
        if (s.find(s[i], i + 1) != std::string::npos) {
            // If the condition is true, print "no" and exit the program
            std::cout << "no" << std::endl;
            return 0;
        }
    }

    // If the for loop completes without finding any matching characters, print "yes"
    std::cout << "yes" << std::endl;

    return 0;
}

// <END-OF-CODE>
