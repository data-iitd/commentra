#include <iostream>

int main() {
    // Declare an integer variable to hold the input seconds
    int S;

    // Read an integer input from the user representing seconds
    std::cin >> S;

    // Check if the input seconds are less than 60
    if (S < 60) {
        // If less than 60 seconds, print the time in the format 0:0:seconds
        std::cout << "0:0:" << S << std::endl;
    }
    // Check if the input seconds are less than 3600 (1 hour)
    else if (S < 3600) {
        // If less than 1 hour, print the time in the format 0:minutes:seconds
        std::cout << "0:" << S / 60 << ":" << S % 60 << std::endl;
    }
    // If the input seconds are 3600 or more (1 hour or more)
    else {
        // Print the time in the format hours:minutes:seconds
        std::cout << S / 3600 << ":" << (S % 3600) / 60 << ":" << S % 60 << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
