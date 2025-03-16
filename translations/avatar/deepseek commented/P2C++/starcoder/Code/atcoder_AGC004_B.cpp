#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the values of n and x
    int n, x;
    cin >> n >> x;
    
    // Read the list of integers a
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Initialize a 2D list b with None values
    // b[j][i] will store the minimum value in the circular array from i to j
    vector<vector<int>> b(n, vector<int>(n));
    
    // Calculate the minimum value in a circular array for each starting position i and ending position j
    for (int i = 0; i < n; i++) {
        int m = a[i];  // Initialize m with the current element
        for (int j = 0; j < n; j++) {
            int k = i - j;  // Calculate the index in the circular array
            if (k < 0) {
                k += n;  // Adjust k if it is negative
            }
            m = min(m, a[k]);  // Update m with the minimum value in the circular array
            b[j][i] = m;  // Store the minimum value in b
    }
    
    // Find the minimum sum of each row in b plus x times the row index
    int m = 1000000001;
    for (int i = 0; i < n; i++) {
        m = min(m, accumulate(b[i].begin(), b[i].end(), 0) + x * i);
    }
    
    // Print the minimum value found
    cout << m << endl;
}

