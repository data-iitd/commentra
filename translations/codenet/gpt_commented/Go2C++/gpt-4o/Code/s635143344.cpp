#include <iostream>
#include <algorithm>
#include <array>

int main() {
    // Create an array to hold three integers
    std::array<int, 3> in;

    // Read three integers from standard input
    std::cin >> in[0] >> in[1] >> in[2];

    // Sort the integers in ascending order
    std::sort(in.begin(), in.end());

    // Calculate the result based on the sorted integers
    // The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
    std::cout << (in[2] * 10 + in[1] + in[0]) << std::endl;

    return 0;
}

// <END-OF-CODE>
