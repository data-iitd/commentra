#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    const int INF = pow(10, 11); // Define a large constant for infinity
    int A, B, Q;
    cin >> A >> B >> Q; // Read the number of temples, shrines, and queries

    vector<int> s(A + 2); // Create a vector for temples with extra space for boundaries
    s[0] = -INF; s[A + 1] = INF; // Set boundary values
    for (int i = 1; i <= A; i++) {
        cin >> s[i]; // Read temple locations
    }

    vector<int> t(B + 2); // Create a vector for shrines with extra space for boundaries
    t[0] = -INF; t[B + 1] = INF; // Set boundary values
    for (int i = 1; i <= B; i++) {
        cin >> t[i]; // Read shrine locations
    }

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x; // Read the query point
        int b = lower_bound(s.begin(), s.end(), x) - s.begin();
        int d = lower_bound(t.begin(), t.end(), x) - t.begin(); // Find closest temples and shrines
        int res = INF; // Initialize result with infinity

        for (int S : {s[b - 1], s[b]}) { // Check previous and current temple
            for (int T : {t[d - 1], t[d]}) { // Check previous and current shrine
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T); // Calculate distances
                res = min(res, min(d1, d2)); // Update result with minimum distance
            }
        }

        cout << res << endl; // Print the minimum distance for the query
    }

    return 0;
}

// <END-OF-CODE>
