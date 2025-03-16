
```cpp
#include <iostream>
#include <cmath>

int main() {
    // Declare variables to hold the input values n and k
    float n, k;

    // Read input values for n and k from the user
    std::cin >> n >> k;

    // Determine the number of digits when n is represented in base k
    // Example: For n = 10 in base 2, it is represented as 1010 which has 4 digits
    // The number of digits is determined by the highest power of k that is less than or equal to n.
    // In this case, we need to find x such that k^x <= n < k^(x+1)
    // The result will be x + 1, which gives the total number of digits.

    float x = 0.0; // Initialize x to 0, which represents the current power of k being evaluated
    while (true) {
        // Calculate k raised to the power of x (lower bound)
        float under = pow(k, x);
        // Calculate k raised to the power of x + 1 (upper bound)
        float upper = pow(k, x + 1);

        // Check if n falls within the range [k^x, k^(x+1))
        if (under <= n && n < upper) {
            // If it does, print the number of digits (which is x + 1) and exit the program
            std::cout << x + 1 << std::endl;
            return 0;
        }
        // Increment x to check the next power of k
        x++;
    }

    return 0;
}

