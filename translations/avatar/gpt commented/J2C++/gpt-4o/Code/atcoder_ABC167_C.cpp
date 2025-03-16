#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // Read the number of rows (n), columns (m), and the minimum required value (x)
    int n, m, x;
    cin >> n >> m >> x;
    
    // Initialize a 2D vector to store the input values
    vector<vector<int>> a(n, vector<int>(m + 1));
    
    // Read the values into the 2D vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    // Initialize the minimum value to a large number
    int min = numeric_limits<int>::max();
    
    // Iterate through all possible combinations of rows using bit manipulation
    for (int i = 0; i < pow(2, n); i++) {
        // Create a vector to track which rows are included in the current combination
        vector<int> status(n, 0);
        
        // Determine which rows are included in the current combination
        for (int j = 0; j < n; j++) {
            if ((1 & (i >> j)) == 1) {
                status[j] = 1;
            }
        }
        
        // Initialize a vector to store the sum of the selected rows
        vector<int> res(m + 1, 0);
        
        // Calculate the sum of the selected rows
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) {
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        
        // Check if the current combination meets the minimum requirement for each column
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = false;
                break;
            }
        }
        
        // If the combination is valid, update the minimum value found
        if (flag) {
            min = std::min(min, res[0]);
        }
    }
    
    // Output the result: -1 if no valid combination was found, otherwise the minimum value
    if (min == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << min << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
