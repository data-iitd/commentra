#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Read an integer input which represents the number of elements
    int n;
    std::cin >> n;

    // Read a line of input, split it into individual integers, and store them in a vector
    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }

    // Initialize the answer with the absolute value of the first element in the vector
    long long ans = std::abs(r[0]);

    // Iterate through the vector starting from the second element
    for (int i = 1; i < n; ++i) {
        // Add the absolute difference between the current element and the previous element to the answer
        ans += std::abs(r[i] - r[i - 1]);
    }

    // Print the final computed answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
