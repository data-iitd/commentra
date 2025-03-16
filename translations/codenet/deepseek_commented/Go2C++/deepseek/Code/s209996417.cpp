#include <iostream>
#include <cmath>

int main() {
    double n, k;
    std::cin >> n >> k;

    // Read two floating-point numbers, n and k, from standard input.
    // These represent the number to be converted and the base of the number system, respectively.

    // Calculate the number of digits in the base k representation of n.
    // The logic involves finding the smallest integer x such that k^x is less than or equal to n and n is less than k^(x+1).
    // Output x + 1 as the number of digits in the base k representation of n.

    double x = 0.0;
    while (true) {
        double under = std::pow(k, x);
        double upper = std::pow(k, x + 1);

        if (under <= n && n < upper) {
            std::cout << x + 1 << std::endl;
            return 0;
        }
        x++;
    }
}
