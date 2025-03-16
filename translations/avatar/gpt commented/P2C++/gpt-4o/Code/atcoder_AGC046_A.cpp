#include <iostream>
#include <numeric> // for std::gcd

int main() {
    // Take an integer input from the user
    int x;
    std::cin >> x;

    // Calculate and print the number of equal parts in a full circle (360 degrees) 
    // that can be formed with the given angle x using the gcd
    std::cout << 360 / std::gcd(360, x) << std::endl;

    return 0;
}

// <END-OF-CODE>
