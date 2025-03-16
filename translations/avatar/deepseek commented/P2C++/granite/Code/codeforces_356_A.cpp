

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Reading the number of elements and number of queries
    vector<int> out(n, 0); // Initializing the output vector with zeros
    vector<int> comp(n, 0); // Initializing the comparison vector with zeros

    // Processing each query
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x; // Reading the query parameters
        int t = l;
        while (t <= r) {
            int next_val = comp[t - 1]; // Getting the next value to compare
            if (out[t - 1] == 0 && t!= x) { // Checking if the current position should be updated
                out[t - 1] = x; // Updating the output vector
            }
            comp[t - 1] = r + 1;
            if (t >= x) {
                comp[t - 1] = x;
            }
            t = next_val; // Moving to the next position in the range
        }
    }

    for (int i = 0; i < n; i++) {
        cout << out[i] << " "; // Outputting the final result
    }
    cout << endl;

    return 0;
}
