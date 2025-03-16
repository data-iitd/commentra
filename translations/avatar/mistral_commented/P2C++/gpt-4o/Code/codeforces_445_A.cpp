#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define the number of rows (n) and columns (m) of the grid
    int n, m;
    cin >> n >> m;

    // Initialize a vector of vectors to store the rows of the grid
    vector<vector<char>> l(n, vector<char>(m));

    // Iterate through each row 'i' in the grid
    for (int i = 0; i < n; i++) {
        // Read the row as a string from user input
        string row;
        cin >> row;

        // Iterate through each cell 'j' in the row
        for (int j = 0; j < m; j++) {
            // If the cell contains a '.', assign it a color based on its position in the grid
            if (row[j] == '.') {
                if ((i + j) % 2) {  // If the row index and column index have different parity
                    row[j] = 'W';   // Assign the cell the color 'W'
                } else {
                    row[j] = 'B';   // Assign the cell the color 'B'
                }
            }
            // Store the processed cell back into the vector
            l[i][j] = row[j];
        }
    }

    // Print each row of the grid
    for (const auto& row : l) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}

// <END-OF-CODE>
