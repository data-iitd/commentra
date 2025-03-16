#include<stdio.h>  // Include standard input-output library for functions like printf and scanf
#include <stdlib.h>  // Include standard library for general utilities like dynamic memory allocation
#include <string.h>  // Include library for string manipulation
#include <math.h>  // Include library for mathematical functions

// Main function where the execution of the program begins
int main() {
    int A, B, C, X;  // Declare variables to store the number of each coin type and the target sum
    int i = 0, j = 0, k = 0;  // Declare and initialize loop counters
    int kosu = 0;  // Declare and initialize a counter for the number of combinations

    // Read the number of each coin type and the target sum from the user
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &X);

    // Normalize the target sum X by dividing it by 50
    X = X / 50;

    // Nested loops to iterate over all possible combinations of the coins
    for (i = 0; i <= A; i++) {  // Loop over the number of 500 yen coins
        for (j = 0; j <= B; j++) {  // Loop over the number of 100 yen coins
            for (k = 0; k <= C; k++) {  // Loop over the number of 50 yen coins
                if (X == (10 * i) + (2 * j) + k) {  // Check if the sum of the coin values equals the normalized target sum
                    kosu++;  // Increment the counter if the condition is met
                }
            }
        }
    }

    // Print the final count of combinations
    printf("%d\n", kosu);

    return 0;  // Return 0 to indicate successful execution of the program
}

