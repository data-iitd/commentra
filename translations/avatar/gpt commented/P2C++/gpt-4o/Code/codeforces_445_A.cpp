#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read two integers n and m from input, representing the number of rows and columns
    int n, m;
    cin >> n >> m;
    cin.ignore(); // To ignore the newline character after reading integers

    // Initialize a vector to store the resulting grid
    vector<vector<char>> grid(n, vector<char>(m));

    // Iterate over each row index i from 0 to n-1
    for (int i = 0; i < n; ++i) {
        // Read a string input for the current row
        string s;
        getline(cin, s);
        
        // Iterate over each column index j from 0 to m-1
        for (int j = 0; j < m; ++j) {
            // Check if the current cell is empty (represented by '.')
            if (s[j] == '.') {
                // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
                if ((i + j) % 2 == 0) {
                    s[j] = 'B';  // Assign 'B' for even sums
                } else {
                    s[j] = 'W';  // Assign 'W' for odd sums
                }
            }
        }
        
        // Store the modified row in the grid
        grid[i] = vector<char>(s.begin(), s.end());
    }

    // Print each row of the grid as a string
    for (const auto& row : grid) {
        for (char c : row) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

// <END-OF-CODE>
