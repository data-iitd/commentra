#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements in the list
    int N;
    std::cin >> N;

    // Read the list of integers from input and store them in a vector
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Initialize minimum and maximum indices for the range of elements that are out of place
    int mn = N + 1, mx = -1;

    // Iterate through the list to find the first and last indices where the element is not in its correct position
    for (int i = 0; i < N; ++i) {
        // Check if the current index + 1 does not match the value at that index
        if ((i + 1) != A[i]) {
            // Update the minimum index if the current index is less than the current minimum
            mn = std::min(mn, i);
            // Update the maximum index if the current index is greater than the current maximum
            mx = std::max(mx, i);
        }
    }

    // If no elements were out of place, output '0 0'
    if (mx == -1) {
        std::cout << "0 0" << std::endl;
    } else {
        // Reverse the subarray from mn to mx
        std::reverse(A.begin() + mn, A.begin() + mx + 1);
        
        // Check if the modified list is sorted
        if (std::is_sorted(A.begin(), A.end())) {
            // If sorted, print the 1-based indices of the range that was reversed
            std::cout << mn + 1 << " " << mx + 1 << std::endl;
        } else {
            // If not sorted, output '0 0'
            std::cout << "0 0" << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
