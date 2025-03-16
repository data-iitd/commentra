#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables N and K with user input
    int N, K;
    scanf("%d %d", &N, &K);

    // Create an array 'v' of size N to store the input integers
    int *v = (int *)malloc(N * sizeof(int));

    // Read N integers from the user and store them in the array 'v'
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    // Calculate the number of subarrays of size K that can be formed from the array 'v'
    int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);

    // Output the result to the console
    printf("%d\n", count);

    // Free the allocated memory
    free(v);

    return 0;
}

// <END-OF-CODE>
