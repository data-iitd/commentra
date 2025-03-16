

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // Read the number of rows and columns
    vector<string> l(n);
    // Initialize a vector to store the rows of the grid
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // Read the row
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                // Check if the cell is a dot
                if ((i + j) % 2 == 0) {
                    s[j] = 'B';
                    // If the sum of row index and column index is even, color the cell 'B'
                } else {
                    s[j] = 'W';
                    // Otherwise, color the cell 'W'
                }
            }
        }
        l[i] = s;
        // Add the processed row to the vector
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] << endl;
        // Print each row as a string
    }
    return 0;
}

