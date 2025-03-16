#include <iostream>

int main() {
    // Declare an integer variable to store the input value.
    int x;

    // Read an integer input from the user and store it in the variable x.
    std::cin >> x;

    // Check the value of x and print 1 or 0 based on the value of x.
    if (x == 0) {
        std::cout << "1" << std::endl;
    }
    if (x == 1) {
        std::cout << "0" << std::endl;
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}

// <END-OF-CODE>
