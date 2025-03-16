#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Define input variables
    long long N, K;
    scanf("%lld %lld", &N, &K);

    // Initialize array 'A' with input values
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Sort array 'A' in ascending order
    qsort(A, N, sizeof(long long), compare);

    // Initialize variables for binary search
    long long ll = -1000000000000000000LL - 1;
    long long rr = 1000000000000000000LL + 1;

    // Perform binary search until 'll + 1' is less than 'rr'
    while (ll + 1 < rr) {
        // Calculate mid value for binary search
        long long x = (ll + rr) / 2;

        // Initialize variable 'tot' to store total count of elements
        long long tot = 0;

        // Iterate through array 'A' and calculate total count of elements that satisfy the condition
        for (long long i = 0; i < N; i++) {
            // Check if current element 'A[i]' is negative
            if (A[i] < 0) {
                // Initialize variables 'l' and 'r' for binary search in the range of indices
                long long l = 0;
                long long r = N;

                // Perform binary search to find the index 'c' such that A[i] * A[c] >= x
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }

                // Update 'tot' with the number of elements greater than 'c'
                tot += N - r;
            } else {
                // If current element 'A[i]' is positive, perform similar binary search and update 'tot' accordingly
                long long l = 0;
                long long r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }

            // Update 'tot' with the contribution of current element 'A[i]'
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }

        // Check if total count of elements is greater than or equal to 'K'
        if (tot >= K) {
            // Update 'll' if condition is satisfied
            ll = x;
        } else {
            // Update 'rr' if condition is not satisfied
            rr = x;
        }
    }

    // Print the final answer
    printf("%lld\n", ll);

    // Free allocated memory
    free(A);

    return 0;
}
