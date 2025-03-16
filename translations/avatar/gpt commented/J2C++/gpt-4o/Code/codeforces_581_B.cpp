#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create an input stream for reading
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of elements
    int n;
    cin >> n;

    // Initialize a vector to hold the input values
    vector<long long> a(n);

    // Populate the vector with input values
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize a dp vector to store the maximum values
    vector<long long> dp(n + 1, -1);

    // Set the last element of dp to the last element of a
    dp[n - 1] = a[n - 1];

    // Fill the dp vector with the maximum values from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], a[i]);
    }

    // Iterate through the original vector to calculate the output
    for (int i = 0; i < n; i++) {
        // If the current element is greater than the next maximum, print 0
        if (a[i] > dp[i + 1]) {
            cout << 0 << " ";
        }
        // Otherwise, calculate and print the difference to the next maximum
        else {
            cout << (dp[i + 1] - a[i] + 1) << " ";
        }
    }

    // Print a new line after all outputs
    cout << endl;

    return 0;
}

// <END-OF-CODE>
