#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read two integers n and m from input, where n is the number of elements and m is the divisor
    int n, m;
    std::cin >> n >> m;

    // Read a list of n integers from input
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    // Initialize an empty vector to store the results after processing the input list
    std::vector<int> l2;

    // Iterate through each element in the input list
    for (int i = 0; i < n; ++i) {
        // If the current element is divisible by m, append the quotient to l2
        if (l[i] % m == 0) {
            l2.push_back(l[i] / m);
        }
        // If the current element is not divisible by m, append the quotient plus one to l2
        else {
            l2.push_back(l[i] / m + 1);
        }
    }

    // Find the maximum value in the processed list l2
    int mx = *std::max_element(l2.begin(), l2.end());

    // Iterate through the range of n to find the index of the maximum value in l2
    int ind = 0; // Initialize index
    for (int i = 0; i < n; ++i) {
        if (l2[i] == mx) {
            ind = i; // Store the index of the maximum value
            break; // Break after finding the first occurrence
        }
    }

    // Print the index of the maximum value (1-based index)
    std::cout << ind + 1 << std::endl;

    return 0;
}

// <END-OF-CODE>
