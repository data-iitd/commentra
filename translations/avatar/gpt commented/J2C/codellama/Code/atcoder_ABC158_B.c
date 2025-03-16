#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the console
    long N, A, B, k;
    scanf("%ld %ld %ld", &N, &A, &B);
    
    // Initialize a variable k to count how many complete cycles of (A + B) can fit into N
    k = 0;

    // Check if the input values are within the specified constraints
    if (1 <= N && N <= pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow(10, 18)) {
        
        // Case 1: If the sum of A and B is less than or equal to N
        if (A + B <= N) {
            // Calculate how many complete cycles of (A + B) fit into N
            k = N / (A + B);
            
            // Check if the remaining part after k cycles is greater than A
            if (N - k * (A + B) > A) {
                // Print the total amount produced using k cycles and the remaining part
                printf("%ld\n", A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)));
            } else {
                // Print the total amount produced using k cycles and the remaining part
                printf("%ld\n", A * k + (N - k * (A + B)));
            }
        } 
        // Case 2: If the sum of A and B is greater than N but A is less than or equal to N
        else if (A + B > N && A <= N) {
            // If A is less than or equal to N, print A
            printf("%ld\n", A);
        } 
        // Case 3: If A + B is greater than N and A is greater than N
        else {
            // Print the total amount N, as no complete cycles can be formed
            printf("%ld\n", N);
        }
    }
    return 0;
}
