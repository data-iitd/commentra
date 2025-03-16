#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k; // Read two integers n and k

    std::vector<int> elements(n); // Create a vector to hold n integers
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i]; // Read n integers into the vector
    }

    std::sort(elements.begin(), elements.end()); // Sort the vector

    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += elements[i]; // Sum the first k smallest elements
    }

    std::cout << sum << std::endl; // Output the sum
    return 0;
}

// <END-OF-CODE>
