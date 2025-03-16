#include <iostream>
#include <numeric> // For std::gcd

int main() {
    // Take an integer input x
    int x;
    std::cin >> x;

    // Calculate the number of distinct cyclic permutations of a string of length x
    std::cout << 360 / std::gcd(360, x) << std::endl;

    return 0;
}

// <END-OF-CODE>
