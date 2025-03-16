// by syu
#include <iostream>
#include <sstream>

int main() {
    // Read the first two integers from the standard input
    int n, k;
    std::cin >> n >> k;

    // Check if n is divisible by k
    if (n % k == 0) {
        // If it is, print 0
        std::cout << 0 << std::endl;
    } else {
        // If not, print 1
        std::cout << 1 << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
