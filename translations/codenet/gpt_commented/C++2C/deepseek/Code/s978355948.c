#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables for the number of elements (N) and the threshold value (X)
    int N, X;
    
    // Read the values of N and X from standard input
    scanf("%d %d", &N, &X);
    
    // Initialize an array L of size N to store the elements
    int *L = (int *)malloc(N * sizeof(int));
    
    // Read N elements into the array L
    for(int i = 0; i < N; i++)
        scanf("%d", &L[i]);
    
    // Initialize index variable and a variable to accumulate the sum
    int i;
    int d = 0;
    
    // Iterate through the elements of the array L
    for(i = 0; i < N; i++) {
        // Accumulate the sum of elements
        d = d + L[i];
        
        // Check if the accumulated sum exceeds the threshold X
        if(d > X)
            break; // Exit the loop if the sum exceeds X
    }

    // Output the number of elements processed before exceeding X
    printf("%d\n", i + 1); // i + 1 because we want to count the number of elements
    
    // Free the allocated memory
    free(L);
    
    return 0;
}
