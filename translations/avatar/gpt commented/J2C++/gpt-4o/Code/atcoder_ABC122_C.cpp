#include <iostream>
#include <vector>

using namespace std;

// Define a constant for the modulo value
const long mod = 1000000007;

int main() {
    // Create a variable to read input
    int n, q;
    
    // Read the number of characters (n) and the number of queries (q)
    cin >> n >> q;
    
    // Read the character array from input
    string c;
    cin >> c;
    
    // Initialize a 2D vector to store the ranges for each query
    vector<vector<int>> range(q, vector<int>(2));
    
    // Read the ranges for each query
    for (int i = 0; i < q; i++) {
        cin >> range[i][0]; // left index of the range
        cin >> range[i][1]; // right index of the range
    }
    
    // Initialize vectors to track fragments and cumulative sums
    vector<int> frag(n + 1, 0); // To count occurrences of "AC"
    vector<int> rui(n + 1, 0);  // To store cumulative sums of fragments
    
    // Loop through the character array to count occurrences of "AC"
    for (int i = 2; i <= n; i++) {
        // Check if the current and previous characters form "AC"
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++; // Increment the fragment count
        }
        // Update the cumulative sum of fragments
        rui[i] = rui[i - 1] + frag[i];
    }
    
    // Process each query to find the number of "AC" in the specified range
    for (int i = 0; i < q; i++) {
        int left = range[i][0];   // Get the left index of the query
        int right = range[i][1];  // Get the right index of the query
        
        // Calculate and print the result for the current query
        cout << rui[right] - rui[left] << endl;
    }
    
    return 0;
}

// <END-OF-CODE>
