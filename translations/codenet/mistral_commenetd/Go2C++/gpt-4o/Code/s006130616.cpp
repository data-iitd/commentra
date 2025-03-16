// Include necessary headers
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Initialize variables n, m, x for input
    int n, m, x;
    cin >> n >> m >> x;

    // Allocate memory for 2D array a and 1D array p
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> p(n);

    // Read input for p and initialize a with input values
    for (int i = 0; i < n; i++) {
        // Read input for p[i]
        cin >> p[i];

        // Read input for each element of row i of a
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Initialize variables ans, tot, and ok
    int ans = numeric_limits<int>::max();
    int tot;
    bool ok;

    // Iterate through all possible combinations of bits
    for (int bits = 0; bits < (1 << n); bits++) {
        // Initialize skill array
        vector<int> skill(m, 0);

        // Calculate total points and update skill array for the current combination of bits
        tot = 0;
        ok = true;
        for (int i = 0; i < n; i++) {
            // Check if the current bit is set
            if ((bits >> i) & 1) {
                // Add points from p[i] to total
                tot += p[i];

                // Update skill array for each skill
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        // Check if the current combination of skills is valid
        for (const auto& v : skill) {
            if (v < x) {
                ok = false;
                break;
            }
        }

        // If the current combination is valid, update ans if the total points are less than the current answer
        if (ok) {
            if (ans > tot) {
                ans = tot;
            }
        }
    }

    // Print the answer
    if (ans != numeric_limits<int>::max()) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

// <END-OF-CODE>
