#include <iostream>

int main() {
    // Declare two integer variables 'n' and 'k'
    int n, k;

    // Read two integers from the standard input using cin
    std::cin >> n >> k;

    // Check if 'n' is divisible by 'k'
    if (n % k == 0) {
        // If it is, print '0' to the standard output
        std::cout << "0" << std::endl;
    } else {
        // If it's not, print '1' to the standard output
        std::cout << "1" << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
