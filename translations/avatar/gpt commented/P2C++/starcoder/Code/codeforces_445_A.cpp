#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read two integers n and m from input, representing the number of rows and columns
    int n, m;
    cin >> n >> m;

    // Initialize an empty list to store the resulting grid
    vector<vector<char>> l;

    // Iterate over each row index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Read a string input for the current row
        string s;
        cin >> s;
        // Convert the string into a list of characters for mutability
        vector<char> v(s.begin(), s.end());

        // Iterate over each column index j from 0 to m-1
        for (int j = 0; j < m; j++) {
            // Check if the current cell is empty (represented by '.')
            if (v[j] == '.') {
                // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
                if ((i + j) & 1) {
                    v[j] = 'W';  // Assign 'W' for odd sums
                } else {
                    v[j] = 'B';  // Assign 'B' for even sums
        }

        // Append the modified row (as a list) to the grid
        l.push_back(v);
    }

    // Print each row of the grid as a string
    for (auto c : l) {
        cout << string(c.begin(), c.end()) << endl;
    }

    return 0;
}

