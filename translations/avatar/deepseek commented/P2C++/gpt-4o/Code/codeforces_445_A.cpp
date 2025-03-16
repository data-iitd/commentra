#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the number of rows and columns
    vector<vector<char>> l(n, vector<char>(m)); // Initialize a 2D vector to store the rows of the grid

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; // Read the row as a string
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                // Check if the cell is a dot
                if ((i + j) % 2 == 1) {
                    s[j] = 'W'; // If the sum of row index and column index is odd, color the cell 'W'
                } else {
                    s[j] = 'B'; // Otherwise, color the cell 'B'
                }
            }
        }
        l[i] = s; // Add the processed row to the vector
    }

    for (const auto& c : l) {
        cout << string(c.begin(), c.end()) << endl; // Print each row as a string
    }

    return 0;
}
// <END-OF-CODE>
