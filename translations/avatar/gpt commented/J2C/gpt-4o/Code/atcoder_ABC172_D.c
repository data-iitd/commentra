#include <stdio.h> // Include standard input-output library

int main() {
    // Declare a variable to hold the user input
    int n;
    
    // Read an integer input from the user
    scanf("%d", &n);
    
    // Initialize a variable to hold the final result
    long long ans = 0;
    
    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long long) i * (n / i) * ((n / i) + 1) / 2;
    }
    
    // Output the final result
    printf("%lld\n", ans);
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
