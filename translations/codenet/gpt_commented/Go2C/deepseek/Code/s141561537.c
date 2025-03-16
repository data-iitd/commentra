#include <stdio.h>

int main() {
    // Declare variables for the number of coins of each type and the target amount
    int a, b, c, x, sum = 0;
    
    // Read input values for the number of coins of each type (a, b, c) and the target amount (x)
    scanf("%d %d %d %d", &a, &b, &c, &x);
    
    // Initialize a loop to iterate through all possible counts of 500 yen coins
    for (int i = 0; i <= a; i++) {
        // Nested loop to iterate through all possible counts of 100 yen coins
        for (int j = 0; j <= b; j++) {
            // Innermost loop to iterate through all possible counts of 50 yen coins
            for (int k = 0; k <= c; k++) {
                // Check if the current combination of coins equals the target amount (x)
                if (500 * i + 100 * j + 50 * k == x) {
                    // If the combination matches, increment the sum of valid combinations
                    sum++;
                }
            }
        }
    }
    
    // Output the total number of combinations that sum up to the target amount
    printf("%d\n", sum);
    
    return 0;
}

