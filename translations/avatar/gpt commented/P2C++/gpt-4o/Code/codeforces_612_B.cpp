#include <iostream>
#include <vector>
#include <cmath> // for abs function

int main() {
    // Read the number of elements
    int n;
    std::cin >> n;

    // Read the elements into a vector and convert them to integers
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Initialize a vector 'b' with zeros to store the positions of elements
    std::vector<int> b(n, 0);

    // Populate the vector 'b' with the indices of elements from vector 'a'
    for (int i = 0; i < n; ++i) {
        b[a[i] - 1] = i; // Store the index of each element in 'b' based on its value in 'a'
    }

    // Initialize the result variable to accumulate the total distance
    long long res = 0;

    // Calculate the total distance between consecutive elements in 'b'
    for (int i = 1; i < n; ++i) {
        res += std::abs(b[i] - b[i - 1]); // Add the absolute difference of indices to the result
    }

    // Print the final result
    std::cout << res << std::endl;

    return 0;
}

// <END-OF-CODE>
