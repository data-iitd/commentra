#include <iostream>  // Include the input-output stream library

int main() {  // Define the main function

    int S;  // Declare an integer variable S
    std::cin >> S;  // Read an integer input from the user and store it in S

    // Check if S is less than 60
    if (S < 60) {
        std::cout << "0:0:" << S << std::endl;  // Print "0:0:S" if S is less than 60
    }
    // Check if S is less than 3600
    else if (S < 3600) {
        std::cout << "0:" << S / 60 << ":" << S % 60 << std::endl;  // Print "0:S/60:S%60" if S is less than 3600
    }
    // If S is not less than 3600
    else {
        std::cout << S / 3600 << ":" << (S % 3600) / 60 << ":" << S % 60 << std::endl;  // Print "S/3600:S%3600/60:S%60" if S is not less than 3600
    }
    return 0;  // Return 0 to indicate successful execution
}  // End of main function

// <END-OF-CODE>
