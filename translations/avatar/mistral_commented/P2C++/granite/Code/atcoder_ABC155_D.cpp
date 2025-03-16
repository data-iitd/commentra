
#####
# Code
#####

# Include necessary libraries
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define input variables
int N, K;

// Define input array 'A'
vector<int> A;

// Define function to perform binary search
int binarySearch(int l, int r, int x) {
    // Perform binary search to find the index 'c' such that A[i] * A[c] >= x
    while (l + 1 < r) {
        int c = (l + r) / 2;
        if (A[i] * A[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

// Define function to calculate total count of elements that satisfy the condition
int calculateTotalCount(int x) {
    int tot = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            int c = binarySearch(0, N, x);
            tot += N - c;
        } else {
            int c = binarySearch(0, N, x);
            tot += c;
        }
        if (A[i] * A[i] < x) {
            tot--;
        }
    }
    return tot;
}

// Main function
int main() {
    // Read input variables
    cin >> N >> K;

    // Read input array 'A'
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Sort input array 'A' in ascending order
    sort(A.begin(), A.end());

    // Initialize variables for binary search
    int ll = -1000000000 - 1;
    int rr = 1000000000 + 1;

    // Perform binary search until 'll + 1' is less than 'rr'
    while (ll + 1 < rr) {
        // Calculate mid value for binary search
        int x = (ll + rr) / 2;

        // Calculate total count of elements that satisfy the condition
        int tot = calculateTotalCount(x);

        // Check if total count of elements is greater than or equal to 'K'
        if (tot >= K) {
            // Update 'll' if condition is satisfied
            ll = x;
        } else {
            // Update 'rr' if condition is not satisfied
            rr = x;
        }
    }

    // Print the final answer
    cout << ll << endl;

    return 0;
}
