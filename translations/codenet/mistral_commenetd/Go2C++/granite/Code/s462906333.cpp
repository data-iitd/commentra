
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e14;

int main() {
    // Setting up logging
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Creating a new scanner object
    int n, x;
    cin >> n >> x;

    // Initializing arrays
    vector<int> a(n), v(n);
    copy(v.begin(), v.end(), a.begin());

    // Initializing answer variable
    int ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; k++) {
        // Initializing variable to store sum of subarray elements
        int kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; i++) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans + k * x);
    }

    // Printing the answer
    cout << ans << endl;

    return 0;
}

