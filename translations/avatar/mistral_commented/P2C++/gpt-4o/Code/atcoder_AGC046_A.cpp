#include <iostream>
#include <numeric> // for std::gcd

int main() {
    // Ask the user for an integer input and assign it to the variable x
    int x;
    std::cin >> x;

    // Calculate the greatest common divisor (gcd) of 360 and the user input x
    int gcd_value = std::gcd(360, x);

    // Print the result of the division of 360 by the gcd
    std::cout << 360 / gcd_value << std::endl;

    return 0;
}

// <END-OF-CODE>
