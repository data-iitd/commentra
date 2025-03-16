

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;  // Number of elements in each list
    std::cin >> n;  // Read the number of elements in each list

    std::vector<int> a(n);  // Create a vector to store the elements of list a
    std::vector<int> b(n);  // Create a vector to store the elements of list b
    std::vector<int> c(n);  // Create a vector to store the elements of list c

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];  // Read the elements of list a
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];  // Read the elements of list b
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];  // Read the elements of list c
    }

    int x = 0;  // Initialize the sum of elements in list a
    int y = 0;  // Initialize the sum of elements in list b
    int z = 0;  // Initialize the sum of elements in list c

    // Calculate the sum of elements in each list
    for (int i = 0; i < n; i++) {
        x += a[i];  // Add each element of list a to x
    }
    for (int i = 0; i < n; i++) {
        y += b[i];  // Add each element of list b to y
    }
    for (int i = 0; i < n; i++) {
        z += c[i];  // Add each element of list c to z
    }

    // Print the absolute differences between the sums of the lists
    std::cout << std::abs(x - y) << std::endl;  // Print the absolute difference between the sums of lists a and b
    std::cout << std::abs(y - z) << std::endl;  // Print the absolute difference between the sums of lists b and c

    return 0;
}
