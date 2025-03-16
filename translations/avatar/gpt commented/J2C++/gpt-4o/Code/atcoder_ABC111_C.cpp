#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a variable to read input from the user
    int n;
    
    // Read the number of elements
    cin >> n;
    
    // Initialize a vector to store the input values
    vector<int> v(n);
    
    // Read n integers from input and store them in the vector v
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Initialize vectors to count occurrences of values at different positions
    vector<int> vo(100010, 0); // Odd indexed counts
    vector<int> ve(100010, 0); // Even indexed counts
    vector<int> vt(100010, 0); // Total counts
    
    // Count occurrences of each number in odd and even indexed positions
    for (int i = 0; i < n; i++) {
        vt[v[i]]++; // Increment total count for the value
        if (i % 2 == 0) {
            ve[v[i]]++; // Increment even indexed count
        } else {
            vo[v[i]]++; // Increment odd indexed count
        }
    }
    
    // Sort the count vectors in descending order
    sort(vo.rbegin(), vo.rend());
    sort(ve.rbegin(), ve.rend());
    sort(vt.rbegin(), vt.rend());
    
    // Initialize the answer variable
    int ans = 0;
    
    // Determine the answer based on the counts of the most frequent elements
    if (vo[0] + ve[0] == vt[0]) {
        // If the most frequent odd and even counts sum to the total count
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        // Otherwise, calculate the answer based on the most frequent counts
        ans = n - vo[0] - ve[0];
    }
    
    // Output the final answer
    cout << ans << endl;
    
    return 0;
}

// <END-OF-CODE>
