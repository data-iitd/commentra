#include <vector>
#include <iostream>
#include <algorithm>

int n, k, t;
std::vector<int> vec;
int ans = 1000000001; // Initialize the answer with a large number

int main() {
    std::cin >> n >> k; // Read the number of elements and the subarray size
    for (int i = 0; i < n; i++) {
        std::cin >> t; // Read each element and add it to the vector
        vec.push_back(t);
    }
    std::sort(vec.begin(), vec.end()); // Sort the vector in ascending order
    for (int i = 0; i + k - 1 < n; i++) { // Iterate through the sorted vector
        int diff = vec[i + k - 1] - vec[i]; // Calculate the difference between the max and min in the subarray
        if (diff < ans) { // Update the answer if the current difference is smaller
            ans = diff;
        }
    }
    std::cout << ans << std::endl; // Output the minimum difference
}