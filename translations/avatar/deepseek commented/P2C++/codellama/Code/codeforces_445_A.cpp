
#include <iostream>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    // Read the number of rows and columns
    char s[n][m];
    // Initialize an array to store the rows of the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            // Read the row and store it in the array
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                if ((i + j) & 1) s[i][j] = 'W';
                // If the sum of row index and column index is odd, color the cell 'W'
                else s[i][j] = 'B';
                // Otherwise, color the cell 'B'
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << s[i][j];
            // Print each cell as a character
        }
        cout << endl;
    }
    // Print each row as a string
    return 0;
}
