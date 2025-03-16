#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int inf = 1e14; // Define a large value to represent infinity for cost comparisons

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x; // Read the number of elements and parameter x
    vector<int> a(n); // Initialize the array a with size n
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Fill the array a with integers from input
    }

    vector<int> v(n); // Create a copy of array a named v
    int ans = inf; // Initialize the answer with a large value

    for (int k = 0; k < n; k++) { // Iterate over possible values of k
        int kans = 0; // Initialize the temporary answer for the current k
        for (int i = 0; i < n; i++) { // Iterate over each element in the array
            if (i - k < 0) { // If the index is out of bounds, wrap around
                v[i] = min(v[i], a[n + i - k]); // Update the value in v
            } else {
                v[i] = min(v[i], a[i - k]); // Update the value in v
            }
            kans += v[i]; // Add the updated value to the temporary answer
        }
        ans = min(ans, kans + k * x); // Update the final answer with the minimum cost
    }

    cout << ans << endl; // Print the minimum cost found
    return 0;
}

// <END-OF-CODE>
