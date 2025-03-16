#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const double inf = 10000000000.0;

int main() {
    int n;
    std::cin >> n; // Reading the size of the array

    std::vector<int> arrA(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arrA[i]; // Reading the elements of the array
    }

    std::vector<int> cumSumA(n + 1, 0); // Initialize the cumulative sum array
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
    }

    double ans = inf; // Initialize the answer with a large number
    for (int i = 1; i < n; i++) {
        double diff = std::abs(cumSumA[n] - (cumSumA[i] * 2));
        if (diff < ans) {
            ans = diff; // Update the answer if a smaller difference is found
        }
    }

    std::cout << static_cast<int>(ans) << std::endl; // Output the minimum difference
    return 0;
}

// <END-OF-CODE>
