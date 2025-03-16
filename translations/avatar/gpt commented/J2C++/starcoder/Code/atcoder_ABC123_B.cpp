#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int a[5];
    int r[5];
    // Create a TreeMap to store the required values for adjustment
    map<int, int> map;
    // Read 5 integers from the user and calculate their remainders
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        r[i] = a[i] % 10;
        // Initialize adjustment value
        int b = 10;
        // If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
        if (r[i]!= 0) {
            b = 10 - r[i];
            // Store the adjustment and the original value in the TreeMap
            map[b] = a[i];
        }
    }
    // Initialize the answer variable to accumulate the result
    int ans = 0;
    // If no adjustments are needed (map is empty), sum all input values
    if (map.size() == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i]; // Add all values to the answer
        }
        cout << ans << endl; // Print the result
        return 0; // Exit the program
    }
    // Get the last key (largest adjustment) from the TreeMap
    int last = map.rbegin()->second;
    int idx = 0;
    // Find the index of the last value in the original array
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i; // Store the index of the last value
        }
    }
    // Calculate the final answer by adding values, adjusting as necessary
    for (int i = 0; i < 5; i++) {
        if (i!= idx) { // Skip the last value
            if (a[i] % 10 == 0) {
                ans += a[i]; // If already a multiple of 10, add directly
            } else {
                ans += a[i] + (10 - r[i]); // Adjust to the next multiple of 10
            }
        }
    }
    // Add the last value to the answer
    ans += last;
    // Print the final calculated answer
    cout << ans << endl;
    return 0;
}

