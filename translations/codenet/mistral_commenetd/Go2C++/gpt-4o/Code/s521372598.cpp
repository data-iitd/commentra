#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n; // Calculate the absolute difference
}

void solve() {
    int n;
    cin >> n; // Read the number of elements in the array
    vector<int> as(n); // Initialize the array as
    for (int i = 0; i < n; ++i) {
        cin >> as[i]; // Read the array elements
    }

    vector<int> xs(n); // Initialize an array xs of size n
    for (int i = 0; i < n; ++i) {
        xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
    }

    sort(xs.begin(), xs.end()); // Sort the array xs in ascending order

    int b = xs[n / 2]; // Assign the middle element of the sorted array xs to variable b
    int ans = 0; // Initialize variable ans with 0
    for (int x : xs) {
        ans += abs(x - b); // Calculate the absolute difference and add it to ans
    }

    cout << ans << endl; // Print the answer
}

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr); // Untie cin from cout

    solve(); // Call the solve function
    return 0;
}

// <END-OF-CODE>
