#include <iostream> // Include the input/output stream library
#include <string>   // Include the string manipulation library

int main(int argc, char *argv[]) { // The main function is the entry point of the program
    std::string s; // Declare a string 's' to store the input string

    std::cin >> s; // Read a string from the standard input and store it in the 's' string

    for (size_t j = 0; j < s.length(); j++) { // Iterate through each character in the string 's' using index 'j'
        for (size_t i = 0; i < s.length(); i++) { // Nested loop to compare each character with all other characters in the string
            if ((i != j) && (s[i] == s[j])) { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                std::cout << "no" << std::endl; // If duplicate characters are found, print 'no' and exit the program
                return 0;
            }
        }
    }

    std::cout << "yes" << std::endl; // If no duplicate characters are found, print 'yes'

    return 0; // Exit the program with a successful return status
}

// <END-OF-CODE>
