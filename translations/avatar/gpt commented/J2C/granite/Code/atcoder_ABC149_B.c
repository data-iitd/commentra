
#include <stdio.h>

int main() {
    // Declare variables to hold the values of A, B, K, and the results x, y
    long A, B, K; 
    long x, y; 

    // Read input values A, B, and K from standard input
    scanf("%ld %ld %ld", &A, &B, &K); 

    // Perform calculations based on the input values
    x = A - K; 
    if (x < 0) {
        y = B + x; 
        x = 0; 
        if (y < 0) {
            y = 0; 
        } 
    } 

    // Display the results of the calculations
    printf("%ld %ld\n", x, y); 

    return 0; 
}
