#include <bits/stdc++.h>
using namespace std;

// Function to calculate the count of numbers in the range [m, m + md - 1]
int sum(int m, int md) {
    // Initialize the result variable to store the total count
    int ret = 0;
    // Initialize the power of ten to track the current range
    int pw = 10;
    // Initialize the length of the current digit
    int length = 1;
    
    // Loop indefinitely until a break condition is met
    while (true) {
        // Calculate the current upper limit for the range
        int cur = min(pw - 1, md);
        // Calculate the previous lower limit for the range
        int prev = pw / 10;
        
        // Update the result with the count of numbers in the current range
        ret += (cur - prev + 1) * length;
        
        // If the current upper limit exceeds md, exit the loop
        if (pw - 1 >= md) {
            break;
        }
        
        // Increase the length for the next range of digits
        length += 1;
        // Move to the next power of ten
        pw *= 10;
    }
    
    // Return the total count of numbers up to md
    return ret;
}

// Main function
int main() {
    // Read input values for w, m, and k
    int w, m, k;
    cin >> w >> m >> k;
    
    // Initialize the lower and upper bounds for binary search
    int lo = 0, hi = 1e18;
    
    // Perform binary search to find the maximum value satisfying the condition
    while (hi - lo > 1) {
        // Calculate the midpoint of the current bounds
        int md = (lo + hi) / 2;
        
        // Calculate the count of numbers in the range [m, m + md - 1]
        int c = sum(m, m + md - 1) - sum(m - 1);
        
        // Check if the count multiplied by k is less than or equal to w
        if (c * k <= w) {
            // If true, adjust the lower bound to md
            lo = md;
        } else {
            // Otherwise, adjust the upper bound to md
            hi = md;
        }
    }
    
    // Print the final result which is the maximum value found
    cout << lo << endl;
    
    return 0;
}

