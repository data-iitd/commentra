#include <iostream>
#include <string>

int main() {
    // Declare a variable 'n' of type string
    std::string n;

    // Read a string input from the user
    std::cin >> n;

    // Initialize a loop counter 'i'
    for (int i = 0; i < 3; i++) {
        // Check if the current character in the string 'n' is equal to '7'
        if (n[i] == '7') {
            // If yes, print "Yes" and exit the function
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    // If no '7' is found in the first three characters, print "No"
    std::cout << "No" << std::endl;

    return 0;
}

// <END-OF-CODE>
