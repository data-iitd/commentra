#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements in the array
    int n;
    std::cin >> n;

    // Read the array elements from input
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Initialize an answer array with zeros, which will store the results
    std::vector<int> ans(n, 0);

    // Set the maximum value to the last element of the array
    int mx = arr[n - 1];

    // Iterate through the array from the second last element to the first
    for (int i = n - 2; i >= 0; --i) {
        // Calculate the required value for ans[i] based on the difference from the maximum
        ans[i] = std::max(0, mx - arr[i] + 1);
        
        // Update the maximum value if the current element is greater than the current maximum
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    // Print the result array as space-separated values
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << (i < n - 1 ? " " : "");
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
