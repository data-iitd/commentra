
#include <stdio.h>

int main() {
    int N, S;
    
    // Continuously read input until a non-positive integer is entered
    while (scanf("%d", &N) == 1 && N > 0) {
        int M = -1, m = 1001, addup = 0, i;
        
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
    
    return 0;
}
