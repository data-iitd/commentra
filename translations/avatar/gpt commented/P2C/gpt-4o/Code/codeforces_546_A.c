#include <stdio.h>

int main() {
    int k, n, w;
    
    // Read input values for k (cost per banana), n (initial amount of money), and w (number of bananas)
    scanf("%d %d %d", &k, &n, &w);
    
    // Check if k is at least 1 and w is at most 1000
    if (k >= 1 && w <= 1000) {
        // Initialize total cost to zero
        long long total = 0; // Use long long to avoid overflow
        
        // Calculate the total cost of buying w bananas
        for (int i = 1; i <= w; i++) {
            total += i * k;  // Cost of each banana increases with its quantity (1*k, 2*k, ..., w*k)
        }
        
        // Check if the total cost exceeds the initial amount of money n
        if (total > n) {
            // Print the amount of money needed to buy the bananas
            printf("%lld\n", total - n);
        } else {
            // Print 0 if the initial amount is sufficient to buy the bananas
            printf("0\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
