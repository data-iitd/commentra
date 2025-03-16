#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    // Read the dimensions of the grid (n) and the number of operations (m)
    int n, m;
    cin >> n >> m;
    
    // Initialize a 2D vector to keep track of counts for each cell in the grid
    vector<vector<int>> count(n, vector<int>(n, 0));
    
    int ans = -1;  // Initialize the answer variable to -1 (indicating no solution found)
    
    // Process each operation
    for (int k = 0; k < m; ++k) {
        // Read the coordinates for the current operation and adjust for 0-based indexing
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        
        bool found = false;  // Flag to indicate if a cell has reached the count of 9
        
        // Iterate over the 3x3 grid centered at (x, y)
        for (int i = x - 2; i <= x + 0; ++i) {
            for (int j = y - 2; j <= y + 0; ++j) {
                // Check if the indices are within the bounds of the grid
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    count[i][j] += 1;  // Increment the count for the current cell
                    
                    // Check if the count for this cell has reached 9
                    if (count[i][j] == 9) {
                        found = true;  // Mark that we found a cell with count 9
                    }
                }
            }
        }
        
        // If a cell with count 9 was found, update the answer and break the loop
        if (found) {
            ans = k + 1;  // Store the 1-based index of the operation
            break;
        }
    }
    
    // Print the result: the operation number where a cell reached count 9, or -1 if none did
    cout << ans << endl;
}

// Call the function to execute the case solving
solve_case();
