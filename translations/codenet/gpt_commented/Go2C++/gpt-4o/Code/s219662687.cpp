#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // Define a large constant for infinity
    const int INF = pow(10, 11);
    
    // Read the number of elements in the first array A and initialize it
    int A;
    cin >> A;
    // Read the number of elements in the second array B
    int B;
    cin >> B;
    // Read the number of queries Q
    int Q;
    cin >> Q;

    // Initialize the first array with boundary values
    vector<int> s(A + 2);
    s[0] = -INF;
    s[A + 1] = INF;
    // Populate the first array with input values
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }

    // Initialize the second array with boundary values
    vector<int> t(B + 2);
    t[0] = -INF;
    t[B + 1] = INF;
    // Populate the second array with input values
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Read the query value x
        int x;
        cin >> x;
        // Find the position in the first array where x would fit
        int b = lower_bound(s.begin(), s.end(), x) - s.begin();
        int d = lower_bound(t.begin(), t.end(), x) - t.begin();
        // Initialize the result with infinity
        int res = INF;

        // Check the closest values in the first array
        for (int S : {s[b - 1], s[b]}) {
            // Check the closest values in the second array
            for (int T : {t[d - 1], t[d]}) {
                // Calculate the distances for both possible paths
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                // Update the result with the minimum distance found
                res = min(res, min(d1, d2));
            }
        }

        // Output the result for the current query
        cout << res << endl;
    }

    return 0;
}

// <END-OF-CODE>
