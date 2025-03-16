#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values: n (number of elements) and x (a multiplier)
    int n, x;
    cin >> n >> x;
    
    // Read the list of integers 'a' from input
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Initialize a 2D vector 'b' with None values to store minimum values
    vector<vector<int>> b(n, vector<int>(n, 0));
    
    // Fill the 2D vector 'b' with minimum values from 'a'
    for (int i = 0; i < n; i++) {
        int m = a[i];  // Start with the current element
        for (int j = 0; j < n; j++) {
            int k = i - j;  // Calculate the index to wrap around
            if (k < 0) {
                k += n;  // Wrap around if index is negative
            }
            m = min(m, a[k]);  // Update m to be the minimum value found
            b[j][i] = m;  // Store the minimum value in the 2D vector 'b'
        }
    }
    
    // Initialize a large value for comparison
    int m = 1000000000;
    
    // Calculate the minimum sum of elements in each row of 'b' plus the weighted index
    for (int i = 0; i < n; i++) {
        m = min(m, accumulate(b[i].begin(), b[i].end(), 0) + x * i);  // Update m with the minimum found
    }
    
    // Print the final minimum value
    cout << m << endl;
    
    return 0;
}

// END-OF-CODE
