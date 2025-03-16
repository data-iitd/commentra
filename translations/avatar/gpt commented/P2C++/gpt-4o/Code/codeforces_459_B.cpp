#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read an integer input for the number of elements
    int n;
    std::cin >> n;

    // Read a line of input, split it into individual integers, and store them in a vector
    std::vector<int> l1(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l1[i];
    }

    // Sort the vector of integers in ascending order
    std::sort(l1.begin(), l1.end());

    // Assign the maximum value in the vector to variable 'a'
    int a = l1[n - 1];

    // Assign the minimum value in the vector to variable 'b'
    int b = l1[0];

    // Check if the maximum and minimum values are the same
    if (a == b) {
        // If they are the same, the difference is zero and the number of pairs is n choose 2
        std::cout << a - b << " " << (n * (n - 1)) / 2 << std::endl;
    } else {
        // Count occurrences of the maximum value 'a' in the vector
        int ac = std::count(l1.begin(), l1.end(), a);
        
        // Count occurrences of the minimum value 'b' in the vector
        int bc = std::count(l1.begin(), l1.end(), b);
        
        // Calculate the difference between the maximum and minimum values, and the product of their counts
        std::cout << a - b << " " << ac * bc << std::endl;
    }

    return 0;
}
// <END-OF-CODE>
