#include <iostream>
#include <vector>
#include <algorithm>

// Define constants for the maximum sizes of arrays S and T
#define N 1000000
#define Q 50000

// Declare variables
int n, S[N], T[Q];

// Function to perform binary search on array S
int binarySearch(int key) {
    int left = 0, right = n, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (S[mid] == key) return 1;
        else if (key < S[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

// Main function
int main() {
    int i, q, c = 0;

    // Read the size of array S
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    // Read the size of array T
    std::cin >> q;
    for (i = 0; i < q; i++) {
        std::cin >> T[i];
        if (binarySearch(T[i]) == 1) c++;
    }

    // Print the count of elements in T that are also in S
    std::cout << c << std::endl;

    return 0;
}
