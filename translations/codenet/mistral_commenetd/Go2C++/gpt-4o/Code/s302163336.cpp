#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements n and m from the standard input
    int n, m;
    cin >> n >> m;

    // Initialize h vector with n elements and good vector with n boolean values
    vector<int> h(n);
    vector<bool> good(n, true);

    // Read n integers from the standard input and initialize h and good vectors
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Process m queries
    for (int i = 0; i < m; i++) {
        // Read two integers ai and bi from the standard input
        int ai, bi;
        cin >> ai >> bi;
        ai--; // Convert to 0-based index
        bi--; // Convert to 0-based index

        // Compare the heights of h[ai] and h[bi]
        if (h[ai] > h[bi]) {
            // If h[ai] is greater than h[bi], mark good[bi] as false
            good[bi] = false;
        } else if (h[ai] < h[bi]) {
            // If h[ai] is less than h[bi], mark good[ai] as false
            good[ai] = false;
        } else {
            // If heights are equal, mark both good[ai] and good[bi] as false
            good[ai] = false;
            good[bi] = false;
        }
    }

    // Initialize answer variable ans to 0
    int ans = 0;

    // Count the number of good elements in the h vector
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            // Increment ans if good[i] is true
            ans++;
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
