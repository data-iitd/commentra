#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the number of rows (n) and columns (m) of the grid
    int n, m;
    cin >> n >> m;

    // Initialize an empty vector 'l' to store the rows of the grid
    vector<string> l;

    // Iterate through each row 'i' in the grid
    for (int i = 0; i < n; i++) {
        // Read the row as a string from user input
        string row;
        cin >> row;

        // Convert the row string into a list for further processing
        vector<char> row_list(row.begin(), row.end());

        // Iterate through each cell 'j' in the row
        for (int j = 0; j < m; j++) {
            // If the cell contains a '.', assign it a color based on its position in the grid
            if (row_list[j] == '.') {
                if ((i + j) % 2) {  // If the row index and column index have different parity
                    row_list[j] = 'W';  // Assign the cell the color 'W'
                } else {
                    row_list[j] = 'B';  // Assign the cell the color 'B'
                }
            }
        }

        // Append the processed row to the list 'l'
        l.push_back(string(row_list.begin(), row_list.end()));
    }

    // Print each row of the grid
    for (string row : l) {
        cout << row << endl;
    }

    return 0;
}
