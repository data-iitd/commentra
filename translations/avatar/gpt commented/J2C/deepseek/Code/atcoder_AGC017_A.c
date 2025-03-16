#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the binomial coefficient C(n, m)
unsigned long long C(int n, int m) {
    unsigned long long res = 1; // Initialize result as 1
    // Calculate the numerator part of the binomial coefficient
    for (int i = m - n + 1; i <= m; i++) 
        res *= i; // Multiply by i from (m-n+1) to m
    
    // Calculate the denominator part of the binomial coefficient
    for (int i = 1; i <= n; i++) 
        res /= i; // Divide by i from 1 to n
    
    return res; // Return the computed binomial coefficient
}

int main() {
    int n, p; // Declare variables for number of elements and parity
    int k0 = 0; // Counter for even numbers
    int k1 = 0; // Counter for odd numbers
    
    // Read the number of elements and the parity value
    scanf("%d %d", &n, &p);
    
    // Count the number of even and odd integers
    for (int i = 0; i < n; i++) {
        int x; // Read the next integer
        scanf("%d", &x);
        if (x % 2 == 1) 
            k1++; // Increment odd counter
        else 
            k0++; // Increment even counter
    }
    
    unsigned long long ans = 1; // Initialize the answer as 1
    
    // Multiply the answer by 2 raised to the power of the number of even integers
    for (int i = 0; i < k0; i++) 
        ans *= 2; // Each even number contributes a factor of 2
    
    // If p is 0, calculate combinations for even selections of odd integers
    if (p == 0) {
        unsigned long long add = 0; // Initialize the sum for combinations
        // Sum the combinations of choosing even numbers of odd integers
        for (int i = 0; i <= k1; i += 2) 
            add += C(i, k1); // Add C(i, k1) for even i
        
        ans *= add; // Multiply the answer by the computed combinations
        printf("%llu\n", ans); // Output the final answer
    } else { // If p is 1, calculate combinations for odd selections of odd integers
        unsigned long long add = 0; // Initialize the sum for combinations
        // Sum the combinations of choosing odd numbers of odd integers
        for (int i = 1; i <= k1; i += 2) 
            add += C(i, k1); // Add C(i, k1) for odd i
        
        ans *= add; // Multiply the answer by the computed combinations
        printf("%llu\n", ans); // Output the final answer
    }
    
    return 0;
}
