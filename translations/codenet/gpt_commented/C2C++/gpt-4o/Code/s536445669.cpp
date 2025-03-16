#include <iostream>

int main() {
    // Declare two integer variables n and k
    int n, k;

    // Read two integers from user input
    std::cin >> n >> k;

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        std::cout << "0" << std::endl;
    } else {
        // If n is not divisible by k, print 1
        std::cout << "1" << std::endl;
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
