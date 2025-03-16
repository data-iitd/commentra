#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Read an integer input which represents the number of elements in the lists
    int n;
    std::cin >> n;

    // Read three lists of integers from input
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    // Initialize variables to hold the sum of each list
    int x = 0, y = 0, z = 0;

    // Calculate the sum of elements in list 'a'
    for (int i : a) {
        x += i;
    }

    // Calculate the sum of elements in list 'b'
    for (int i : b) {
        y += i;
    }

    // Calculate the sum of elements in list 'c'
    for (int i : c) {
        z += i;
    }

    // Print the absolute difference between the sums of list 'a' and list 'b'
    std::cout << std::abs(x - y) << std::endl;

    // Print the absolute difference between the sums of list 'b' and list 'c'
    std::cout << std::abs(y - z) << std::endl;

    return 0;
}

// <END-OF-CODE>
