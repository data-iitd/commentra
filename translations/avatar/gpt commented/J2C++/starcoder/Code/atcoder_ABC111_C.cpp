#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;
    
    // Initialize an array to store the input values
    int v[100010];
    
    // Read n integers from input and store them in the array v
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // Initialize arrays to count occurrences of values at different positions
    int vo[100010]; // Odd indexed counts
    int ve[100010]; // Even indexed counts
    int vt[100010]; // Total counts
    
    // Fill the count arrays with zeros
    fill(vo, vo + 100010, 0);
    fill(ve, ve + 100010, 0);
    fill(vt, vt + 100010, 0);
    
    // Count occurrences of each number in odd and even indexed positions
    for (int i = 0; i < n; i++) {
        vt[v[i]]++; // Increment total count for the value
        if (i % 2 == 0) {
            ve[v[i]]++; // Increment even indexed count
        } else {
            vo[v[i]]++; // Increment odd indexed count
        }
    }
    
    // Sort the count arrays in descending order
    sort(vo, vo + 100010, greater<int>());
    sort(ve, ve + 100010, greater<int>());
    sort(vt, vt + 100010, greater<int>());
    
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

