#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values for N (number of elements) and K (threshold count)
    int N, K;
    cin >> N >> K;

    // Read the list of integers and sort it
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    // Initialize the lower and upper bounds for binary search
    long long ll = -1000000000 - 1;
    long long rr = 1000000000 + 1;

    // Perform binary search to find the maximum value x such that the count of pairs (i, j) with A[i] * A[j] < x is at least K
    while (ll + 1 < rr) {
        // Calculate the mid-point of the current bounds
        long long x = (ll + rr) / 2;
        int tot = 0;  // Initialize the total count of valid pairs

        // Iterate through each element in the sorted list A
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {  // If the current element is negative
                int l = -1;
                int r = N;
                // Perform binary search to find the count of elements that can form a valid pair with A[i]
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {  // Check if the product is less than x
                        r = c;  // Move the right bound down
                    } else {
                        l = c;  // Move the left bound up
                    }
                }
                // Count how many elements can form a valid pair with A[i]
                tot += N - r;
            } else {  // If the current element is non-negative
                int l = -1;
                int r = N;
                // Perform binary search to find the count of elements that can form a valid pair with A[i]
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {  // Check if the product is less than x
                        l = c;  // Move the left bound up
                    } else {
                        r = c;  // Move the right bound down
                    }
                }
                // Count how many elements can form a valid pair with A[i]
                tot += r;
            }

            // Adjust the total count if A[i] forms a pair with itself
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }

        // Since each pair (i, j) is counted twice, divide the total count by 2
        tot /= 2;

        // Adjust the binary search bounds based on the total count of pairs
        if (tot < K) {
            ll = x;  // If the count is less than K, move the lower bound up
        } else {
            rr = x;  // If the count is at least K, move the upper bound down
        }
    }

    // Print the final result, which is the largest x found
    cout << ll << endl;

    return 0;
}

