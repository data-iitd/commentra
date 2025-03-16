#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Reading the number of elements and number of queries
    vector<int> out(n, 0); // Initializing the output list with zeros
    vector<int> comp(n);
    
    for (int i = 0; i < n; ++i) {
        comp[i] = i + 2; // Initializing the comparison list with values from 2 to n+1
    }

    // Processing each query
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x; // Reading the query parameters
        int t = l;
        while (t <= r) {
            int next_val = comp[t - 1]; // Getting the next value to compare
            if (out[t - 1] == 0 && t != x) { // Checking if the current position should be updated
                out[t - 1] = x; // Updating the output list
            }
            comp[t - 1] = (t >= x) ? (r + 1) : x; // Updating the comparison list based on the condition
            t = next_val; // Moving to the next position in the range
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << out[i] << " "; // Outputting the final result
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
