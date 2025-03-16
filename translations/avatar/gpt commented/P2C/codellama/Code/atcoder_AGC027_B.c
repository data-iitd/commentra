#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Read input values: N (number of elements), X (a constant), and A (the list of integers)
    int N, X, *A, i;
    scanf("%d %d", &N, &X);
    A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    // Calculate the cumulative sum of the list A
    int *S = (int *)malloc((N + 1) * sizeof(int));
    S[0] = 0;
    for (i = 1; i <= N; i++)
        S[i] = S[i - 1] + A[i - 1];

    // Initialize the answer to a very large number (infinity)
    int ans = 1000000000;

    // Iterate through the cumulative sums with an index starting from 1
    for (i = 1; i <= N; i++)
    {
        // Calculate the expression E based on the current index k and the cumulative sums
        int E = i * X + 2 * (S[N - 2 * i - 1] - S[N - i - 1]);

        // Update the answer with the minimum value found so far
        if (E < ans)
            ans = E;
    }

    // Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
    printf("%d\n", ans + N * X + 5 * S[N]);

    // Free the memory allocated for the list A and the cumulative sums
    free(A);
    free(S);

    return 0;
}

