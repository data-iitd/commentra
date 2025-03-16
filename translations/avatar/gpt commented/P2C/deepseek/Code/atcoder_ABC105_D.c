#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculate cumulative remainders of the array A when divided by M
    // Start with a 0 to handle the case of subarrays starting from index 0
    int *cum_remainders = (int*)malloc((N + 1) * sizeof(int));
    cum_remainders[0] = 0;
    for (int i = 1; i <= N; i++) {
        cum_remainders[i] = (cum_remainders[i - 1] + A[i - 1]) % M;
    }

    // Sort the cumulative remainders
    qsort(cum_remainders, N + 1, sizeof(int), compare);

    // Count the occurrences of each remainder
    int count = 1;
    long long combinations = 0;
    for (int i = 1; i <= N; i++) {
        if (cum_remainders[i] == cum_remainders[i - 1]) {
            count++;
        } else {
            combinations += (long long)count * (count - 1) / 2;
            count = 1;
        }
    }
    combinations += (long long)count * (count - 1) / 2;

    // Output the total number of combinations found
    printf("%lld\n", combinations);

    // Free allocated memory
    free(A);
    free(cum_remainders);

    return 0;
}
