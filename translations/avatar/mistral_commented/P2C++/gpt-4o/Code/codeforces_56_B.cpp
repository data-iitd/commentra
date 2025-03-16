#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Read the number of elements in the list 'A'
    int N;
    std::cin >> N;

    // Initialize a vector 'A' with the given size 'N' and read the elements from the standard input
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Initialize minimum and maximum indices 'mn' and 'mx'
    int mn = N + 1, mx = -1;

    // Iterate through the vector 'A' from index 0 to 'N-1'
    for (int i = 0; i < N; ++i) {
        // Check if the current index 'i' is not equal to the next element
        if (i + 1 != A[i]) {
            // Update the minimum and maximum indices 'mn' and 'mx'
            mn = std::min(mn, i);
            mx = std::max(mx, i);
        }
    }

    // Check if the maximum index 'mx' is still equal to -1
    if (mx == -1) {
        // If yes, print '0 0' as the output
        std::cout << "0 0" << std::endl;
    } else {
        // Slice the vector 'A' based on the indices 'mn' and 'mx+1'
        std::vector<int> newA;
        newA.insert(newA.end(), A.begin(), A.begin() + mn);
        std::vector<int> toReverse(A.begin() + mn, A.begin() + mx + 1);
        std::reverse(toReverse.begin(), toReverse.end());
        newA.insert(newA.end(), toReverse.begin(), toReverse.end());
        newA.insert(newA.end(), A.begin() + mx + 1, A.end());

        // Check if the sliced vector 'newA' is sorted in ascending order
        if (std::is_sorted(newA.begin(), newA.end())) {
            // If yes, print the minimum and maximum indices 'mn+1' and 'mx+1' as the output
            std::cout << mn + 1 << " " << mx + 1 << std::endl;
        } else {
            // If no, print '0 0' as the output
            std::cout << "0 0" << std::endl;
        }
    }

    return 0;
}
// <END-OF-CODE>
