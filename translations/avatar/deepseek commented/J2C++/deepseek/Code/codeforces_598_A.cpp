#include <iostream>
#include <cmath>

int main() {
    int q;
    std::cin >> q; // Read the number of queries

    while (q--) {
        int n;
        std::cin >> n; // Read the number n for the current query

        long long s = 0; // Initialize the sum variable s

        int x = static_cast<int>(log(n) / log(2)) + 1; // Calculate the position of the most significant bit of n

        s = -1 * static_cast<long long>(pow(2, x)) + 2 + (static_cast<long long>(n) * (n + 1)) / 2 - static_cast<long long>(pow(2, x));
        // Calculate s using arithmetic operations and power functions

        std::cout << s << std::endl; // Print the result s for the current query
    }

    return 0;
}
