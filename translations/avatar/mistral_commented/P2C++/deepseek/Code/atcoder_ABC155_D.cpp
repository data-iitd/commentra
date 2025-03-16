#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Define input variables
    int N, K;
    cin >> N >> K;

    // Initialize vector 'A' with input values
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort vector 'A' in ascending order
    sort(A.begin(), A.end());

    // Initialize variables for binary search
    long long ll = -1e18 - 1;
    long long rr = 1e18 + 1;

    // Perform binary search until 'll + 1' is less than 'rr'
    while (ll + 1 < rr) {
        // Calculate mid value for binary search
        long long x = (ll + rr) / 2;

        // Initialize variable 'tot' to store total count of elements
        long long tot = 0;

        // Iterate through vector 'A' and calculate total count of elements that satisfy the condition
        for (int i = 0; i < N; ++i) {
            // Check if current element 'A[i]' is negative
            if (A[i] < 0) {
                // Initialize variables 'l' and 'r' for binary search in the range of indices
                int l = 0;
                int r = N;

                // Perform binary search to find the index 'c' such that A[i] * A[c] >= x
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }

                // Update 'tot' with the number of elements greater than 'c'
                tot += N - r;

            } else {
                // If current element 'A[i]' is positive, perform similar binary search and update 'tot' accordingly
                int l = 0;
                int r = N;
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }

            // Update 'tot' with the contribution of current element 'A[i]'
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }

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
