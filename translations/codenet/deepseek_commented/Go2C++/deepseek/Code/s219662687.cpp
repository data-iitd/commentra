#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int nextInt() {
    int num;
    cin >> num;
    return num;
}

int abs(int x) {
    return abs(x);
}

int min(int x, int y) {
    return min(x, y);
}

int max(int x, int y) {
    return max(x, y);
}

int main() {
    const int INF = INT_MAX; // Define a large constant for infinity
    int A = nextInt(); // Read the number of temples
    int B = nextInt(); // Read the number of shrines
    int Q = nextInt(); // Read the number of queries
    vector<int> s(A + 2); // Create a vector for temples with extra space for boundaries
    s[0] = -INF; s[A + 1] = INF; // Set boundary values
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt(); // Read temple locations
    }

    vector<int> t(B + 2); // Create a vector for shrines with extra space for boundaries
    t[0] = -INF; t[B + 1] = INF; // Set boundary values
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt(); // Read shrine locations
    }

    for (int i = 0; i < Q; i++) {
        int x = nextInt(); // Read the query point
        int b = lower_bound(s.begin(), s.end(), x) - s.begin(); // Find closest temples
        int d = lower_bound(t.begin(), t.end(), x) - t.begin(); // Find closest shrines
        int res = INF; // Initialize result with infinity
        for (int S : {s[b - 1], s[b]}) { // Check previous and current temple
            for (int T : {t[d - 1], t[d]}) { // Check previous and current shrine
                int d1 = abs(S - x) + abs(T - S); // Calculate distances
                int d2 = abs(T - x) + abs(S - T); // Calculate distances
                res = min({res, d1, d2}); // Update result with minimum distance
            }
        }

        cout << res << endl; // Print the minimum distance for the query
    }

    return 0;
}
