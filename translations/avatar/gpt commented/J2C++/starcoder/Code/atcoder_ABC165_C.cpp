#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare variables for input values and dimensions
    int n, m, q;
    cin >> n >> m >> q;
    
    // Declare arrays to hold input values and variables for dimensions and result
    int a[q], b[q], c[q], d[q];
    long ans = -100L; // Initialize answer to a very low value
    
    // Read the query parameters into the arrays
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    // Start the depth-first search (DFS) to find the maximum score
    dfs(a, b, c, d, n, m, q, ans);
    
    // Output the maximum score found
    cout << ans << endl;
}

// Function to start the DFS
void dfs(int a[], int b[], int c[], int d[], int n, int m, int q, long &ans) {
    // Check if the current list has reached the required size (n)
    if (n == 0) {
        long score = 0L; // Initialize score for the current configuration
        
        // Calculate the score based on the queries
        for (int i = 0; i < q; ++i) {
            // If the condition is met, add the corresponding value to the score
            score += (b[i] - a[i] == c[i])? d[i] : 0L;
        }
        
        // Update the maximum score if the current score is higher
        ans = max(ans, score);
        return;
    }
    
    // If the list is not empty, continue adding numbers from the last added number to m
    if (n > 0) {
        for (int num = a[n - 1]; num <= m; ++num) {
            a[n] = num; // Add the current number to the list
            dfs(a, b, c, d, n - 1, m, q, ans); // Recur with the updated list
            a[n] = 0; // Backtrack by removing the last number
        }
    } else {
        // If the list is empty, start adding numbers from 1 to m
        for (int num = 1; num <= m; ++num) {
            a[n] = num; // Add the current number to the list
            dfs(a, b, c, d, n - 1, m, q, ans); // Recur with the updated list
            a[n] = 0; // Backtrack by removing the last number
        }
    }
}

