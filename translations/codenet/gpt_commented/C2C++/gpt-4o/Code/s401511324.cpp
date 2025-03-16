#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Declare variables
    int n, cnt = 0;

    // Read the number of elements
    std::cin >> n;
    std::vector<int> l(n);

    // Input the elements into the array
    for(int i = 0; i < n; i++) {
        std::cin >> l[i];
    }

    // Sort the array
    std::sort(l.begin(), l.end());

    // Count the number of valid triplets (i, j, k) such that l[i] + l[j] > l[k]
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                // Check if the sum of two elements is greater than the third
                if(l[i] + l[j] > l[k]) {
                    cnt++; // Increment count if the condition is satisfied
                } else {
                    break; // Break if the condition is not satisfied (since array is sorted)
                }
            }
        }
    }

    // Output the count of valid triplets
    std::cout << cnt << std::endl;

    return 0;
}

// <END-OF-CODE>
