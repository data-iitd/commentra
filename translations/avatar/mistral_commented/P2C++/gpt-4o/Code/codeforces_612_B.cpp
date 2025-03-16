#include <iostream>
#include <vector>
#include <cmath> // for abs function

int main() {
    // Take an integer 'n' as input
    int n;
    std::cin >> n;

    // Initialize a vector 'a' of 'n' integers by taking input
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Initialize an empty vector 'b' of length 'n'
    std::vector<int> b(n, 0);

    // Assign indices to 'b' based on the values in 'a'
    for (int i = 0; i < n; ++i) {
        // Assign index 'i' to the position 'a[i] - 1' in vector 'b'
        b[a[i] - 1] = i;
    }

    // Initialize a variable 'res' to 0
    int res = 0;

    // Calculate the absolute difference between consecutive indices in 'b' and sum them up
    for (int i = 1; i < n; ++i) {
        // Add the absolute difference between indices 'i' and 'i-1' to 'res'
        res += std::abs(b[i] - b[i - 1]);
    }

    // Print the final result 'res'
    std::cout << res << std::endl;

    return 0;
}

// <END-OF-CODE>
