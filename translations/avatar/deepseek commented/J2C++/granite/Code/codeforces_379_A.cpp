

#include <iostream>
#include <cmath>

int main() {
    int a, b, res;
    std::cin >> a >> b; // Read the first and second integers from the user
    res = a; // Initialize result variable with the value of a

    // Enter a while loop that continues as long as a is greater than or equal to b
    while (a >= b) {
        res += a / b; // Update result by adding the integer division of a by b
        a = a / b + a % b; // Update a to be the sum of the integer division and remainder
    }

    std::cout << res << std::endl; // Print the final value of res

    return 0;
}

