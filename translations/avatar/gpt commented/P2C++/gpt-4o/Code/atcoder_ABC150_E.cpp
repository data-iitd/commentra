#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const int mod = 1e9 + 7;

int main() {
    // Read the number of elements
    int n;
    std::cin >> n;

    // Read the list of integers
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    // Sort the list in descending order
    std::sort(c.rbegin(), c.rend());

    // Calculate the value of b as 2^(2*n - 2) modulo mod
    long long b = 1;
    for (int i = 0; i < 2 * n - 2; ++i) {
        b = (b * 2) % mod;
    }

    // Calculate the value of a as 2 * b modulo mod
    long long a = (2 * b) % mod;

    // Initialize the answer variable
    long long ans = 0;

    // Iterate through the sorted list and calculate the answer
    for (int i = 0; i < n; ++i) {
        // Update the answer by adding the product of the current element and (a + i * b)
        ans = (ans + c[i] * (a + i * b)) % mod;
    }

    // Print the final result
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
