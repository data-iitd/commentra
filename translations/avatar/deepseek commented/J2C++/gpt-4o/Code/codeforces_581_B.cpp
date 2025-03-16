#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Step 4: Read input values
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 5: Initialize a dynamic programming array
    vector<long long> dp(n + 1, -1);

    // Step 6: Fill the dynamic programming array
    dp[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], a[i]);
    }

    // Step 7: Calculate the result
    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            cout << 0 << " ";
        } else {
            cout << (dp[i + 1] - a[i] + 1) << " ";
        }
    }

    // Step 8: Print the result
    cout << endl;
    return 0;
}

// <END-OF-CODE>
