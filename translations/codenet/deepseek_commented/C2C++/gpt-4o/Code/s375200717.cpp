#include <iostream>

int main() {
    int n, i, a;

    // Read an integer n from the standard input
    std::cin >> n;

    // Iterate from 1 to n (inclusive)
    for (i = 1; i <= n; i++) {
        a = i;

        // Check if the current number i is divisible by 3
        if ((a % 3) == 0) {
            std::cout << " " << i;
        } else {
            // Check each digit of i to see if it contains the digit 3
            for (; a; ) {
                if ((a % 10) == 3) {
                    std::cout << " " << i;
                    a = 0;
                }
                a = a / 10;
            }
        }
    }

    // Print a newline character
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
