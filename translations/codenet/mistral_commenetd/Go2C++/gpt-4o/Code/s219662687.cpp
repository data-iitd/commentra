// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Main function
int main() {
    const int INF = static_cast<int>(pow(10, 11)); // Large constant value for initializing arrays

    // Reading input values
    int A, B, Q;
    cin >> A >> B >> Q;

    // Initializing arrays s and t with size A+2 and B+2 respectively
    vector<int> s(A + 2), t(B + 2);
    s[0] = -INF; s[A + 1] = INF;

    // Reading A elements of array s
    for (int i = 1; i <= A; i++) {
        cin >> s[i];
    }

    // Initializing array t
    t[0] = -INF; t[B + 1] = INF;

    // Reading B elements of array t
    for (int i = 1; i <= B; i++) {
        cin >> t[i];
    }

    // Processing each query
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        // Finding the indices b and d of array s and t respectively
        int b = lower_bound(s.begin(), s.end(), x) - s.begin();
        int d = lower_bound(t.begin(), t.end(), x) - t.begin();

        // Computing the minimum distance
        int res = INF;
        for (int S : {s[b - 1], s[b]}) {
            for (int T : {t[d - 1], t[d]}) {
                // Computing the absolute difference
                int d1 = abs(S - x);
                int d2 = abs(T - S);

                // Updating the minimum distance
                res = min(res, min(d1, d2));
            }
        }

        // Printing the minimum distance for the current query
        cout << res << endl;
    }

    return 0;
}

// <END-OF-CODE>
