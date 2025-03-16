#include <iostream>

int main() {
    // Loop to iterate 5 times
    for (int i = 0; i < 5; i++) {
        int a; // Declare a variable 'a' to store user input
        std::cin >> a; // Read an integer input from the user and store it in 'a'
        
        // Check if the input value is zero
        if (a == 0) {
            // Print the current iteration index + 1 if the input is zero
            std::cout << (i + 1) << std::endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
