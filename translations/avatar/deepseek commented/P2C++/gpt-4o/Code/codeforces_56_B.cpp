#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;  // Read the integer input N
    std::vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];  // Read the list of integers A
    }

    // Initialize variables to track the minimum and maximum indices where the condition is true
    int mn = N + 1, mx = -1;

    // Iterate over the range of N to find the indices where the condition is true
    for (int i = 0; i < N; ++i) {
        if ((i + 1) != A[i]) {
            mn = std::min(mn, i);  // Update mn if a smaller index is found
            mx = std::max(mx, i);  // Update mx if a larger index is found
        }
    }

    // Check if no indices satisfy the condition
    if (mx == -1) {
        std::cout << "0 0" << std::endl;  // Print '0 0' if no indices satisfy the condition
    } else {
        // Reverse the sublist from index mn to mx + 1
        std::reverse(A.begin() + mn, A.begin() + mx + 1);
        
        // Check if the list A is sorted
        if (std::is_sorted(A.begin(), A.end())) {
            std::cout << mn + 1 << " " << mx + 1 << std::endl;  // Print the indices if A is sorted
        } else {
            std::cout << "0 0" << std::endl;  // Print '0 0' if A is not sorted
        }
    }

    return 0;
}  // <END-OF-CODE>
