#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read the number of elements n and m from the standard input
    int n, m;
    cin >> n >> m;

    // Initialize h array with n elements and good array with n boolean values
    vector<int> h(n);
    vector<bool> good(n, true);

    // Read n integers from the standard input and initialize h and good arrays
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Process m queries
    for (int i = 0; i < m; i++) {
        // Read two integers ai and bi from the standard input
        int ai, bi;
        cin >> ai >> bi;

        // Compare the heights of h[ai-1] and h[bi-1]
        if (h[ai-1] > h[bi-1]) {
            // If h[ai-1] is greater than h[bi-1], mark good[bi-1] as false
            good[bi-1] = false;
        } else if (h[ai-1] < h[bi-1]) {
            // If h[ai-1] is less than h[bi-1], mark good[ai-1] as false
            good[ai-1] = false;
        } else {
            // If heights are equal, mark both good[ai-1] and good[bi-1] as false
            good[ai-1] = false;
            good[bi-1] = false;
        }
    }

    // Initialize answer variable ans to 0
    int ans = 0;

    // Count the number of good elements in the h array
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

