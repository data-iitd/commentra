
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Reading Input
    // The code reads input values for N, X, and a list of integers A.
    // This is done using scanf and malloc.
    int N, X;
    scanf("%d %d", &N, &X);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Step 2: Accumulating Sums
    // The code uses a for loop to calculate the accumulated sums of A.
    // This is stored in the array S.
    int *S = (int *)malloc(N * sizeof(int));
    S[0] = A[0];
    for (int i = 1; i < N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    // Step 3: Initializing Answer
    // The variable ans is initialized to infinity (INT_MAX).
    int ans = INT_MAX;

    // Step 4: Calculating Energy
    // The code uses a for loop to iterate over the accumulated sums S with an index k starting from 1.
    // For each k, it calculates the energy E using the formula k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k)).
    // It then updates ans with the minimum value between the current ans and the calculated E.
    for (int k = 1; k <= N / 3; k++) {
        int E = k * X + 2 * (S[N - 1] - S[N - 2 * k - 1]);
        ans = ans < E? ans : E;
    }

    // Step 5: Final Calculation
    // After the loop, the code calculates the final result by adding ans to N * X + 5 * S[N - 1] and prints it.
    printf("%d\n", ans + N * X + 5 * S[N - 1]);

    // Step 6: Freeing Memory
    // The code frees the memory allocated for A and S.
    free(A);
    free(S);

    return 0;
}
