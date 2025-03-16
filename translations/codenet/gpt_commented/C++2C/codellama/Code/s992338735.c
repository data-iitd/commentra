#include <stdio.h>

int N, S;

int main() {
    // Continuously read input until a non-positive integer is entered
    while (scanf("%d", &N) == 1 && N > 0) {
        int M, m, addup, i;
        
        // Initialize M to a very low value and m to a very high value
        M = -1; // Maximum value initialized to -1 (less than any possible input)
        m = 1001; // Minimum value initialized to 1001 (greater than any possible input)
        addup = 0; // Variable to accumulate the sum of inputs
        
        // Loop to read N integers
        for (i = 0; i < N; i++) {
            scanf("%d", &S); // Read the next integer
            
            addup += S; // Add the current integer to the total sum
            
            // Update the maximum value if the current integer is greater
            if (S > M) M = S;
            
            // Update the minimum value if the current integer is smaller
            if (S < m) m = S;
        }
        
        // Calculate the average excluding the maximum and minimum values
        // and print the result
        printf("%d\n", (addup - M - m) / (N - 2));
    }
}

