#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Take input dimensions and threshold from user
    int n, m, x;
    cin >> n >> m >> x;

    // Initialize vector 'c' with dimensions (n, m)
    vector<vector<int>> c(n, vector<int>(m));

    // Loop through all rows of 'c'
    for (int i = 0; i < n; i++) {
        // Loop through all columns of 'c'
        for (int j = 0; j < m; j++) {
            // Take input value for 'c' at row 'i' and column 'j'
            cin >> c[i][j];
        }
    }

    // Initialize empty vector 'l' for storing combinations and 'rem' for storing indices
    vector<vector<int>> l;
    vector<int> rem;

    // Initialize variable 'ans' for storing minimum number of tests
    int ans = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= n; i++) {
        // Generate all combinations of 'pre' indices of size 'i'
        for (int j = 0; j < (1 << i); j++) {
            // Initialize empty vector 'temp' for storing current combination
            vector<int> temp;

            // Loop through each bit of 'j'
            for (int k = 0; k < i; k++) {
                // If the bit is set, add the corresponding index to 'temp'
                if (j & (1 << k)) {
                    temp.push_back(k);
                }
            }

            // If 'temp' is not empty, append it to 'l'
            if (temp.size() > 0) {
                l.push_back(temp);
            }
        }
    }

    // Loop through each iteration 'i' of test cases
    for (int i = 1; i <= m; i++) {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each index 'j' in current combination
        for (int j = 0; j < l[i].size(); j++) {
            // Add the test result at index 'j' and test case 'i' to 'ca'
            ca += c[l[i][j]][i];
        }

        // If the sum of tests in current combination is less than threshold 'x',
        // add the index of the current combination to 'rem' list
        if (ca < x) {
            rem.insert(rem.begin(), i);
        }
        // If the sum of tests in current combination is greater than or equal to threshold 'x',
        // continue to next combination
        else {
            continue;
        }

        // If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
        if (rem.size() > 0) {
            for (int j = 0; j < rem.size(); j++) {
                l.erase(l.begin() + rem[j]);
            }
            rem.clear();
        }

        // If 'l' list is empty, print -1 and break the loop
        if (l.size() == 0) {
            cout << -1 << endl;
            break;
        }
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    if (l.size() > 0) {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each valid combination and calculate the sum of tests
        for (int i = 0; i < l.size(); i++) {
            ca = 0;
            for (int j = 0; j < l[i].size(); j++) {
                ca += c[l[i][j]][0];
            }

            // Update 'ans' with minimum number of tests among all valid combinations
            if (ans == 0) {
                ans = ca;
            } else {
                ans = min(ans, ca);
            }
        }

        // Print the minimum number of tests required
        cout << ans << endl;
    }

    return 0;
}

