#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Take the number of test cases as input
    int n;
    std::cin >> n;

    // Read the first list 'a' of numbers
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Read the second list 'b' of numbers
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Read the third list 'c' of numbers
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i];
    }

    // Initialize variables x, y, and z to 0
    int x = 0, y = 0, z = 0;

    // Iterate through each number in list 'a' and add it to the variable 'x'
    for (int i : a) {
        x += i;
    }

    // Iterate through each number in list 'b' and add it to the variable 'y'
    for (int i : b) {
        y += i;
    }

    // Iterate through each number in list 'c' and add it to the variable 'z'
    for (int i : c) {
        z += i;
    }

    // Print the absolute difference between 'x' and 'y'
    std::cout << std::abs(x - y) << std::endl;

    // Print the absolute difference between 'y' and 'z'
    std::cout << std::abs(y - z) << std::endl;

    return 0;
}

// <END-OF-CODE>
