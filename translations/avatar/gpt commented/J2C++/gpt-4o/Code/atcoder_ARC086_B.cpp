#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    // Create a variable to read input from the user
    int n;
    
    // Read the number of elements in the array
    std::cin >> n;
    
    // Initialize a vector to hold the integers
    std::vector<int> a(n);
    
    // Populate the vector with user input
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // Create a vector to store the result pairs
    std::vector<std::string> r;
    
    // Variable to track the index of the element with the maximum absolute value
    int m = 0;
    
    // Find the index of the element with the maximum absolute value
    for (int i = 1; i < n; ++i) {
        if (std::abs(a[m]) < std::abs(a[i])) {
            m = i;
        }
    }
    
    // Generate pairs of indices based on the sign of the maximum absolute value element
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) {
            r.push_back(std::to_string(m + 1) + " " + std::to_string(i + 1));
        }
    }
    
    // If the maximum absolute value element is non-negative
    if (a[m] >= 0) {
        // Add pairs of consecutive indices in ascending order
        for (int i = 1; i < n; ++i) {
            r.push_back(std::to_string(i) + " " + std::to_string(i + 1));
        }
    } else {
        // If the maximum absolute value element is negative, add pairs in descending order
        for (int i = n; i > 1; --i) {
            r.push_back(std::to_string(i) + " " + std::to_string(i - 1));
        }
    }
    
    // Print the size of the result list
    std::cout << r.size() << std::endl;
    
    // Print each pair in the result list
    for (const auto& pair : r) {
        std::cout << pair << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
