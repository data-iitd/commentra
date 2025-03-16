
```cpp
#include <bits/stdc++.h>
using namespace std;

// Define a large constant for infinity
const int inf = 1e14;

// ---------------------------------------------------------
int main() {
    // Set log flags to show the file name and line number
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Initialize a new scanner for input
    auto next = [&]() {
        string s;
        cin >> s;
        return s;
    };

    // Read the number of elements and the value of x
    int n = stoi(next());
    int x = stoi(next());

    // Create a vector to hold the input integers
    vector<int> a(n);

    // Read n integers into the vector a
    for (int i = 0; i < n; i++) {
        a[i] = stoi(next());
    }

    // Create a copy of the vector a for manipulation
    vector<int> v = a;

    // Initialize the answer to infinity
    int ans = inf;

    // Iterate over each possible k value
    for (int k = 0; k < n; k++) {
        int kans = 0; // Initialize the current answer for this k

        // Calculate the minimum values for the current k
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                // If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Otherwise, use the normal index
                v[i] = min(v[i], a[i - k]);
            }
            // Accumulate the current answer
            kans += v[i];
        }

        // Update the overall answer with the minimum found so far
        ans = min(ans, kans + k * x);
    }

    // Print the final answer
    cout << ans << endl;
}

