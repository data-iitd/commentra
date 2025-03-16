
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // Taking input from the user and splitting it into two integers
    // Assigning the values to variables `n` and `k`

    vector<int> M(n);
    for (int i = 0; i < n; i++) {
        cin >> M[i];
        // Taking another input from the user, which is supposed to be a list of integers
        // Storing them in the vector `M`
    }

    int m = 0;
    // Initializing a variable `m` to 0

    for (int j = 0; j < n; j++) {
        // Starting a loop that will iterate `n` times
        for (int p = 0; p < n; p++) {
            // Starting another loop that will iterate `n` times
            if (M[p] == 0) {
                // Checking if the element at position `p` in the vector `M` is 0
                cout << p + 1 << " ";
                // If the condition is true, print the position `p + 1`
                break;
                // Break out of the loop after printing the position
            }
        }
        for (int l = 0; l < p + 1 - k; l++) {
            M[l]--;
            // Decreasing the elements in the vector `M` from position 0 to `p - k` by 1
        }
        M[p]--;
        // Decreasing the element at position `p` by 1
    }

    return 0;
}
