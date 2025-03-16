#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input values for w, m, and k
    int w, m, k;
    scanf("%d %d %d", &w, &m, &k);
    
    // Initialize the lower and upper bounds for binary search
    int lo = 0, hi = 1e18;
    
    // Perform binary search to find the maximum value satisfying the condition
    while (hi - lo > 1) {
        // Calculate the midpoint of the current bounds
        int md = (lo + hi) / 2;
        
        // Calculate the count of numbers in the range [m, m + md - 1]
        int c = sum(m + md - 1) - sum(m - 1);
        
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
    printf("%d\n", lo);
    
    return 0;
}

// Function to calculate the count of numbers in the range [m, m + k - 1]
int sum(int k) {
    // Initialize the result variable to store the total count
    int ret = 0;
    // Initialize the power of ten to track the current range
    int pw = 10;
    // Initialize the length of the current digit
    int length = 1;
    
    // Loop indefinitely until a break condition is met
    while (1) {
        // Calculate the current upper limit for the range
        int cur = min(pw - 1, k);
        // Calculate the previous lower limit for the range
        int prev = pw / 10;
        
        // Update the result with the count of numbers in the current range
        ret += (cur - prev + 1) * length;
        
        // If the current upper limit exceeds k, exit the loop
        if (pw - 1 >= k) {
            break;
        }
        
        // Increase the length for the next range of digits
        length += 1;
        // Move to the next power of ten
        pw *= 10;
    }
    
    // Return the total count of numbers up to k
    return ret;
}

// Function to return the minimum of two values
int min(int a, int b) {
    return a < b? a : b;
}

