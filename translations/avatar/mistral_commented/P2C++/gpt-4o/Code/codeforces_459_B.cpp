#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n; // Read the number of elements in the list
    std::vector<int> l1(n); // Create a vector to hold the list elements

    for (int i = 0; i < n; ++i) {
        std::cin >> l1[i]; // Read the list elements
    }

    std::sort(l1.begin(), l1.end()); // Sort the list in ascending order

    int a = l1[n - 1]; // Assign the last element of the sorted list to the variable a
    int b = l1[0]; // Assign the first element of the sorted list to the variable b

    if (a == b) { // Check if the first and the last elements are equal
        std::cout << a - b << " " << (n * (n - 1)) / 2 << std::endl; // If so, calculate and print the result
    } else {
        int ac = std::count(l1.begin(), l1.end(), a); // Count the number of occurrences of the element a in the list
        int bc = std::count(l1.begin(), l1.end(), b); // Count the number of occurrences of the element b in the list
        std::cout << a - b << " " << ac * bc << std::endl; // Print the result
    }

    return 0;
} // <END-OF-CODE>
