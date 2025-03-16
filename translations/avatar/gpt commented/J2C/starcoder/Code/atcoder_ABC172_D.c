#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an integer input from the user
    int n;
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
