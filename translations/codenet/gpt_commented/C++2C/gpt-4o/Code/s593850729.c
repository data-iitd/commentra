#include <stdio.h>

int main() {
    // Declare variables to hold the maximum counts of each denomination and the target amount
    int A, B, C, X;
    
    // Read input values for the maximum counts of 500, 100, 50 yen coins and the target amount
    scanf("%d %d %d %d", &A, &B, &C, &X);
  
    // Initialize a counter to keep track of the number of combinations that sum to X
    int cnt = 0;

    // Iterate through all possible counts of 500 yen coins (from 0 to A)
    for (int a = 0; a <= A; a++) { 
        // Iterate through all possible counts of 100 yen coins (from 0 to B)
        for (int b = 0; b <= B; b++) {
            // Iterate through all possible counts of 50 yen coins (from 0 to C)
            for (int c = 0; c <= C; c++) {
                // Calculate the total amount using the current counts of coins
                int total = 500 * a + 100 * b + 50 * c;
                
                // Check if the calculated total matches the target amount X
                if (total == X) 
                    // If it matches, increment the counter
                    cnt++;
            }
        }
    }

    // Output the total number of combinations that sum to X
    printf("%d\n", cnt);
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
