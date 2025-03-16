#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements from standard input
    int n;
    std::cin >> n;

    // Initialize a vector to hold the input integers
    std::vector<int> a(n);
    // Read n integers from standard input into the vector a
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Initialize a vector b to hold the longest increasing subsequence
    std::vector<int> b;
    // Iterate over each value in the input vector a
    for (const auto& v : a) {
        // Use binary search to find the index where v can be placed in b
        auto it = std::lower_bound(b.begin(), b.end(), v);
        // If v is greater than all elements in b, append it to b
        if (it == b.end()) {
            b.push_back(v);
        } else {
            // Otherwise, replace the existing value at index it with v
            *it = v;
        }
    }

    // Output the length of the longest increasing subsequence
    std::cout << b.size() << std::endl;

    return 0;
}

// <END-OF-CODE>
