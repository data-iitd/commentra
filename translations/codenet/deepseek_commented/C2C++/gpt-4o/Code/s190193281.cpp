#include <iostream>
#include <vector>
#include <algorithm>

// Define constants for the maximum sizes of arrays S and T
const int N = 1000000;
const int Q = 50000;

// Declare variables
int n;
std::vector<int> S(N);
std::vector<int> T(Q);

// Function to perform binary search on array S
bool binarySearch(int key) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (S[mid] == key) return true;
        else if (key < S[mid]) right = mid;
        else left = mid + 1;
    }
    return false;
}

// Main function
int main() {
    int q, c = 0;

    // Read the size of array S
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    // Sort array S to prepare for binary search
    std::sort(S.begin(), S.begin() + n);

    // Read the size of array T
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> T[i];
        if (binarySearch(T[i])) c++;
    }

    // Print the count of elements in T that are also in S
    std::cout << c << std::endl;

    return 0;
}

// <END-OF-CODE>
