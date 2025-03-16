#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;  // Read two integers n and m from input
    std::vector<int> l(n);  // Initialize a vector to store the list of integers
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];  // Read the list of integers
    }

    std::vector<int> l2;  // Initialize an empty vector to store the results

    // Iterate over each element in the vector l
    for (int i : l) {
        if (i % m == 0) {  // Check if the element is divisible by m
            l2.push_back(i / m);  // Append the quotient to l2
        } else {
            l2.push_back(i / m + 1);  // Append the quotient plus one to l2
        }
    }

    int mx = *std::max_element(l2.begin(), l2.end());  // Find the maximum value in l2

    // Iterate over l2 to find the index of the maximum value
    int ind = 0;  // Initialize index
    for (int i = 0; i < n; ++i) {
        if (l2[i] == mx) {
            ind = i;  // Store the index of the maximum value
            break;  // Break after finding the first occurrence
        }
    }

    std::cout << ind + 1 << std::endl;  // Print the index of the maximum value plus one

    return 0;
}  // <END-OF-CODE>
