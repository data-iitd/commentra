#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Declare variables for the number of participants (n), number of skills (m), and the minimum skill level required (x)
    int n, m, x;
    // Read input values for n, m, and x
    cin >> n >> m >> x;

    // Initialize a 2D vector to hold skill levels and a vector for participant points
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> p(n);
    // Read participant points and their respective skill levels
    for (int i = 0; i < n; i++) {
        // Read the points for participant i
        cin >> p[i];
        // Read the skill levels for participant i
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Initialize the answer to a large number and other variables for tracking total points and skill validation
    int ans = 1200001;
    int tot = 0;
    bool ok = true;

    // Iterate through all possible combinations of participants using bit manipulation
    for (int bits = 0; bits < (1 << n); bits++) {
        // Reset total points and skill validation flag for the current combination
        tot = 0;
        ok = true;
        // Initialize a vector to accumulate skill levels for the current combination
        vector<int> skill(m, 0);

        // Check each participant to see if they are included in the current combination
        for (int i = 0; i < n; i++) {
            if (bits & (1 << i)) {
                // Add the points of the selected participant to the total
                tot += p[i];
                // Accumulate the skill levels of the selected participant
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        // Check if the accumulated skill levels meet the minimum requirement
        for (int v : skill) {
            if (v < x) {
                ok = false; // If any skill level is below x, mark as not okay
                break;
            }
        }

        // If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
        if (ok) {
            ans = min(ans, tot);
        }
    }

    // Output the result: the minimum points needed or -1 if no valid combination was found
    if (ans != 1200001) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
