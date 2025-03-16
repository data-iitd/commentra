#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables N and K to hold the number of elements and the divisor respectively
    int N, K;
    
    // Read the values of N and K from standard input
    scanf("%d %d", &N, &K);

    // Initialize a vector of size N to store the input elements
    int *v = (int *)malloc(N * sizeof(int));
    
    // Read N integers from standard input and store them in the vector v
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]);

    // Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
    // This is done using integer arithmetic to avoid floating-point operations
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
    
    // Output the calculated count of groups
    printf("%d\n", count);

    // Free the memory allocated for the vector v
    free(v);

    // End of code
    printf("