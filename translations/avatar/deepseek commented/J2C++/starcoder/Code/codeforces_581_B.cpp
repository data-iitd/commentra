#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Step 4: Read input values
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 5: Initialize a dynamic programming array
    long long dp[n + 1];
    memset(dp, -1, sizeof(dp));

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
    cout << "\n";

    return 0;
}

