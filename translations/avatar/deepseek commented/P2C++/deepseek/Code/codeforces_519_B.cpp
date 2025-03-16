#include <iostream>
#include <vector>
#include <cmath>  // For std::abs

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in each list

    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);

    // Read the first list of integers
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Read the second list of integers
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Read the third list of integers
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    int x = 0;  // Initialize the sum of elements in list a
    int y = 0;  // Initialize the sum of elements in list b
    int z = 0;  // Initialize the sum of elements in list c

    // Calculate the sum of elements in each list
    for (int i : a) {
        x += i;  // Add each element of list a to x
    }
    for (int i : b) {
        y += i;  // Add each element of list b to y
    }
    for (int i : c) {
        z += i;  // Add each element of list c to z
    }

    // Print the absolute differences between the sums of the lists
    std::cout << std::abs(x - y) << std::endl;  // Print the absolute difference between the sums of lists a and b
    std::cout << std::abs(y - z) << std::endl;  // Print the absolute difference between the sums of lists b and c

    return 0;
}

