
#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q); // Read the number of queries
    
    while (q--) {
        int n;
        scanf("%d", &n); // Read the number n for the current query
        long long s = 0; // Initialize the sum variable s
        
        int x = (int)(log2(n)); // Calculate the position of the most significant bit of n
        x++; // Increment x by 1
        
        s = -1 * pow(2, x) + 2 + (long long)n * (long long)(n + 1) / 2 - (long long)pow(2, x); 
        // Calculate s using arithmetic operations and power functions
        
        printf("%lld\n", s); // Print the result s for the current query
    }
    
    return 0;
}
// END-OF-CODE