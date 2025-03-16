#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read two integers `n` and `k` from the standard input, separated by a space
    int n, k;
    std::cin >> n >> k;

    // Create a vector of integers
    std::vector<int> numbers(n);

    // Read `n` integers from the standard input
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Calculate the sum of the first `k` elements of the sorted vector
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result += numbers[i];
    }

    // Print the result
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
