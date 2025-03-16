#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int n, k;
    
    // Read the number of elements in the array and the number of queries
    cin >> n >> k;
    
    // Initialize a vector to hold the input values
    vector<int> arr(n);
    
    // Populate the vector with input values
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // String to store the results of the queries
    string res;
    
    // Counters for the number of 1s (o) and 0s (e) in the array
    int o = 0, e = 0;
    
    // Count the number of 1s and 0s in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ++o; // Increment count of 1s
        } else {
            ++e; // Increment count of 0s
        }
    }
    
    // Process each query
    for (int i = 0; i < k; i++) {
        // Read the left and right indices for the current query
        int l, r;
        cin >> l >> r;
        
        // Check if the number of elements in the range is odd
        if ((r - l + 1) % 2 == 1) {
            res += "0\n"; // If odd, append "0" to results
        } else {
            // If even, check if we can form a valid pair of 1s and 0s
            if ((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) {
                res += "1\n"; // Append "1" if valid pairs can be formed
            } else {
                res += "0\n"; // Otherwise, append "0"
            }
        }
    }
    
    // Output the results of all queries
    cout << res;
    
    return 0;
}

// <END-OF-CODE>
