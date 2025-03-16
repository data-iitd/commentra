#include <iostream>

int main() {
    // Read two integers `n` and `m` from the standard input, separated by a space
    int n, m;
    std::cin >> n >> m;

    // Initialize a variable `i` to 1
    int i = 1;

    // The while loop starts
    while (m >= i) {
        // Subtract `i` from `m`
        m -= i;

        // Update the value of `i` by calculating `(i % n) + 1`
        i = (i % n) + 1;
    }

    // Once the loop finishes, print the final value of `m` to the standard output
    std::cout << m << std::endl;

    return 0;
}

// <END-OF-CODE>
