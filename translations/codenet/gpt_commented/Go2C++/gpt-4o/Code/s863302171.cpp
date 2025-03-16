#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the input string
    std::string n;
    
    // Read input from the user and store it in variable n
    std::cin >> n;
    
    // Loop through the first three characters of the input string
    for (int i = 0; i < 3; i++) {
        // Check if the current character is '7'
        if (n[i] == '7') {
            // If '7' is found, print "Yes" and exit the program
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    
    // If '7' is not found in the first three characters, print "No"
    std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
