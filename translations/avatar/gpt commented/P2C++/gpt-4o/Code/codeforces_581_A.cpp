#include <iostream>
#include <algorithm> // for std::min and std::max

int main() {
    int a, b;
    // Read two integers from input
    std::cin >> a >> b;

    // Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
    std::cout << std::min(a, b) << " " << (std::max(a, b) - std::min(a, b)) / 2 << std::endl;

    return 0;
}

// <END-OF-CODE>
