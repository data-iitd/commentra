#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define the number of elements 'n' and the modulus 'm' in the list 'l'
    int n, m;
    std::cin >> n >> m;

    // Initialize a vector 'l' to store the elements
    std::vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i]; // Input the elements of the list
    }

    // Initialize a vector 'l2' to store the quotient of each element in 'l' divided by 'm'
    std::vector<int> l2(n);

    // Iterate through each element 'i' in the list 'l'
    for (int i = 0; i < n; ++i) {
        // Check if the element 'i' is divisible by 'm'
        if (l[i] % m == 0) {
            l2[i] = l[i] / m; // Append the quotient (integer division) to 'l2'
        } else {
            l2[i] = l[i] / m + 1; // Append the quotient plus one
        }
    }

    // Find the maximum quotient in 'l2'
    int mx = *std::max_element(l2.begin(), l2.end());

    // Initialize the index variable
    int ind = -1;

    // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
    for (int i = 0; i < n; ++i) {
        // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'
        if (l2[i] == mx) {
            ind = i; // Store the index 'i' in the variable 'ind'
            break; // Break after finding the first occurrence
        }
    }

    // Print the index 'ind' plus one (since the indices in C++ start from 0)
    std::cout << ind + 1 << std::endl;

    return 0;
}

// <END-OF-CODE>
