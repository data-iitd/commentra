#include <iostream>
#include <vector>
#include <cmath> // For abs function

int main() {
    int n;
    std::cin >> n; // Take an integer input representing the length of the list `a`
    
    std::vector<int> a(n); // Initialize a vector `a` of length `n`
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // Take space-separated integers and store them in `a`
    }
    
    std::vector<int> b(n, 0); // Initialize a vector `b` of length `n` with all elements set to 0

    // Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i;
    }

    int res = 0; // Initialize the result variable `res` to 0

    // Calculate the sum of absolute differences between the positions of consecutive elements in `b`
    for (int i = 1; i < n; ++i) {
        res += std::abs(b[i] - b[i - 1]);
    }

    std::cout << res << std::endl; // Print the result

    return 0;
} // <END-OF-CODE>
