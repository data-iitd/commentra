// by syu
#include <iostream>

int main() {
    // Read two integers, n and k, from the input.
    int n, k;
    std::cin >> n >> k;

    // Check if n is divisible by k.
    if (n % k == 0) {
        // If n is divisible by k, print 0.
        std::cout << 0 << std::endl;
    } else {
        // If n is not divisible by k, print 1.
        std::cout << 1 << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
