#include <iostream>
#include <vector>

int main() {
    // Read input values for n and k
    int n, k;
    std::cin >> n >> k;

    // Read the list of integers M from input
    std::vector<int> M(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> M[i];
    }

    // Outer loop to iterate over each index j in the range of n
    for (int j = 0; j < n; ++j) {
        // Inner loop to find the first index p where M[p] is zero
        int p;
        for (p = 0; p < n; ++p) {
            if (M[p] == 0) {
                // Print the index (1-based) where M[p] is zero
                std::cout << p + 1 << ' ';
                break;
            }
        }

        // Decrease the values in M from the start up to p + 1 - k
        for (int l = 0; l < p + 1 - k; ++l) {
            M[l] -= 1;
        }

        // Decrease the value at index p in M
        M[p] -= 1;
    }

    return 0;
}
// <END-OF-CODE>
