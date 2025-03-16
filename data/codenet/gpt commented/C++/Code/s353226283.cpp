#include <vector>
#include <iostream>
#include <algorithm>

// Declare global variables
int n, k, t; // n: number of elements, k: size of the subset, t: temporary variable for input
std::vector<int> vec; // Vector to store the input elements
int ans = 1000000001; // Initialize ans to a large value to find the minimum difference

int main() {
    // Read the number of elements (n) and the size of the subset (k)
    std::cin >> n >> k;

    // Read n integers from input and store them in the vector
    for (int i = 0; i < n; i++) {
        std::cin >> t; // Read each integer
        vec.push_back(t); // Add the integer to the vector
    }

    // Sort the vector in non-decreasing order
    std::sort(vec.begin(), vec.end());

    // Iterate through the sorted vector to find the minimum difference
    for (int i = 0; i + k - 1 < n; i++) {
        // Calculate the difference between the maximum and minimum of the current subset of size k
        int diff = vec[i + k - 1] - vec[i];
        
        // Update the minimum difference found so far
        if (diff < ans) {
            ans = diff; // Update ans if a smaller difference is found
        }
    }

    // Output the minimum difference found
    std::cout << ans << std::endl;

    return 0; // Return 0 to indicate successful completion
}
