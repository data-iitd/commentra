#include <iostream>
#include <vector>

int main() {
    // Read the input from the user
    int n, m;
    std::cin >> n >> m;

    // Calculate the quotient and remainder of n divided by m
    int q = n / m;
    int r = n % m;

    // Initialize a vector with q repeated m times
    std::vector<int> a(m, q);

    // Increment the corresponding elements in the a vector for the remaining elements
    for (int i = 0; i < r; ++i) {
        a[i] += 1;
    }

    // Print each element of the a vector separated by a space
    for (int i = 0; i < m; ++i) {
        std::cout << a[i] << ' ';
    }

    return 0;
}

// <END-OF-CODE>
