#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    // Read the dimensions of the grid and the number of operations
    int n, m;
    cin >> n >> m;
    
    // Initialize a count grid with all elements set to 0
    vector<vector<int>> count(n, vector<int>(n, 0));
    
    // Initialize the answer to -1
    int ans = -1;
    
    // Loop through each operation
    for (int k = 0; k < m; ++k) {
        // Read the coordinates of the operation
        int x, y;
        cin >> x >> y;
        
        // Adjust the coordinates to zero-based index
        --x;
        --y;
        
        // Flag to check if a cell in the 3x3 grid reaches a count of 9
        bool found = false;
        
        // Check the 3x3 grid centered at (x, y)
        for (int i = x - 2; i <= x; ++i) {
            for (int j = y - 2; j <= y; ++j) {
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    ++count[i][j];
                    if (count[i][j] == 9) {
                        found = true;
                    }
                }
            }
        }
        
        // If a cell in the 3x3 grid reaches a count of 9, update ans and break
        if (found) {
            ans = k + 1;
            break;
        }
    }
    
    // Print the result
    cout << ans << endl;
}

int main() {
    solve_case();
    return 0;
}

