#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Read the values of N and M from the standard input
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the array A from the standard input
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    // Calculate the cumulative remainders of the array A modulo M
    // Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
    int *cum_remainders = (int *)malloc((N + 1) * sizeof(int));
    cum_remainders[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Count the occurrences of each remainder
    int *remainder_counts = (int *)malloc(M * sizeof(int));
    memset(remainder_counts, 0, M * sizeof(int));
    for (int i = 1; i <= N; i++)
    {
        remainder_counts[cum_remainders[i]]++;
    }

    // Initialize the number of combinations
    int combinations = 0;

    // Calculate the number of combinations where the difference between two remainders is a multiple of M
    for (int i = 0; i < M; i++)
    {
        combinations += remainder_counts[i] * (remainder_counts[i] - 1) / 2;
    }

    // Print the number of combinations
    printf("%d\n", combinations);

    // Free the memory allocated for the arrays
    free(A);
    free(cum_remainders);
    free(remainder_counts);

    return 0;
}

