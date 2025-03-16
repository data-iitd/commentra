#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Use fast input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Initialize the previous value to infinity
    int pre = numeric_limits<int>::max();

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Sort the list in descending order
    sort(a.rbegin(), a.rend());

    // Iterate through the sorted list
    for (int j = 0; j < n; ++j) {
        // Calculate the current contribution to the answer
        // It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
        ans += max(0LL, min(pre - 1, a[j]));

        // Update the previous value for the next iteration
        pre = max(0, min(pre - 1, a[j]));
    }

    // Print the final accumulated answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
