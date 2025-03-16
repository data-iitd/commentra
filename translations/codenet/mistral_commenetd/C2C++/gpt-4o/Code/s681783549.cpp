#include <iostream>  // Include input/output stream library
#include <string>    // Include string library

int main() {  // Beginning of the main function
    std::string S;  // Declare a string variable 'S'

    std::cin >> S;  // Read a string from the standard input and store it in 'S'

    for (size_t i = 0; i < S.length(); i++) {  // Iterate through each character in the string 'S'
        if (S[i] == 'A' && S[i + 1] == 'C') {  // Check if the current character is 'A' and the next character is 'C'
            std::cout << "Yes" << std::endl;  // If so, print 'Yes' to the standard output
            return 0;  // And exit the program
        }
    }

    std::cout << "No" << std::endl;  // If no pair of 'AC' is found, print 'No' to the standard output
    return 0;  // End of the main function
}  // <END-OF-CODE>
