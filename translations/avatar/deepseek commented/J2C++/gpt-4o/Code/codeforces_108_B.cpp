#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n; // Read the size of the array
    std::vector<int> a(n); // Initialize the array of size n
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; // Populate the array with n integers
    }
    std::sort(a.begin(), a.end()); // Sort the array
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) { // Check if any element is less than twice the previous element
            std::cout << "YES" << std::endl; 
            return 0; // Exit the program after printing "YES"
        }
    }
    std::cout << "NO" << std::endl; // Print "NO" if no such condition is found
    return 0;
}

// <END-OF-CODE>
