#include <iostream>

int main() {
    // Declare an integer variable to hold the input value
    int n;

    // Read an integer value from standard input
    std::cin >> n;

    // Check if n is a multiple of 1000
    if (n % 1000 == 0) 
        // If true, print 0 since no additional amount is needed to reach the next multiple of 1000
        std::cout << 0 << std::endl;
    else 
        // If false, calculate and print the difference to the next multiple of 1000
        std::cout << (n / 1000 + 1) * 1000 - n << std::endl;

    return 0;
}

// <END-OF-CODE>
