#include <iostream>
#include <cmath>

int main() {
    double n, k;
    std::cin >> n >> k;

    // Calculate the number of digits in the base k representation of n.
    // The logic involves finding the smallest integer x such that k^x is less than or equal to n
    // and n is less than k^(x+1). Output x + 1 as the number of digits in the base k representation of n.

    double x = 0.0;
    while (true) {
        double under = pow(k, x);
        double upper = pow(k, x + 1);

        if (under <= n && n < upper) {
            std::cout << static_cast<int>(x + 1) << std::endl;
            return 0;
        }
        x++;
    }
}

// <END-OF-CODE>
