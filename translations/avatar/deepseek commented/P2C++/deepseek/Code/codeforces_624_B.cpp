#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Step 1: Reading the number of elements (n)
    int n;
    cin >> n;

    // Step 2: Reading the list of elements (a)
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Step 3: Initializing variables
    int pre = INT_MAX;  // Initialize pre to infinity
    int ans = 0;  // Initialize ans to 0

    // Step 4: Sorting the list in descending order
    sort(a.rbegin(), a.rend());

    // Step 5: Iterating through the list
    for (int j = 0; j < n; ++j) {
        // Calculate the maximum value that can be added to ans
        ans += max(0, min(pre - 1, a[j]));
        // Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
        pre = max(0, min(pre - 1, a[j]));
    }

    // Step 6: Printing the result
    cout << ans << '\n';

    return 0;
}
