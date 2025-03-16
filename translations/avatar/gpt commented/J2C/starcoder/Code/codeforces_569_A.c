#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int T, S, q, answer;
    long previous;
    
    // Read three integers from the input: T, S, and q
    scanf("%d %d %d", &T, &S, &q);
    
    // Initialize 'previous' with the starting value S
    previous = S;
    
    // Initialize the answer counter
    answer = 0;
    
    // Loop until 'previous' is less than 'T'
    while (previous < T) {
        answer++; // Increment the answer counter
        previous *= q; // Multiply 'previous' by 'q' for the next iteration
    }
    
    // Output the final count of how many times 'previous' was multiplied before reaching 'T'
    printf("%d\n", answer);
    
    return 0;
}
