#include <iostream>
#include <algorithm> // for std::max

int main() {
    int a, b;
    std::cin >> a >> b; // Taking two integer inputs, `a` and `b`

    int c = 0; // Initializing a variable `c` to 0

    for (int i = 0; i < 2; i++) { // The loop runs twice
        c += std::max(a, b); // Adding the maximum of `a` and `b` to `c`
        if (a >= b) { // Checking if `a` is greater than or equal to `b`
            a--; // Decrementing `a` by 1 if the condition is true
        } else {
            b--; // Decrementing `b` by 1 if the condition is false
        }
    }

    std::cout << c << std::endl; // Printing the value of `c` after the loop completes
    return 0;
}

// <END-OF-CODE>
