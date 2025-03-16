#include <stdio.h>

int main() {
    // Create a variable to hold the user input
    int n;
    
    // Read an integer input from the user
    scanf("%d", &n);
    
    // Initialize a variable to hold the final result
    long ans = 0;
    
    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i < n + 1; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long) i * ((long) n / (long) i) * (((long) n / (long) i) + 1) / 2;
    }
    
    // Output the final result
    printf("%ld\n", ans);
    
    return 0;
}

