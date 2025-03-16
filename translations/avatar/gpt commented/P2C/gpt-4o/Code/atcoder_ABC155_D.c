#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read input values for N (number of elements) and K (threshold count)
    int N, K;
    scanf("%d %d", &N, &K);

    // Read the list of integers
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Sort the array
    qsort(A, N, sizeof(long long), compare);

    // Initialize the lower and upper bounds for binary search
    long long ll = -1000000000000000000LL - 1;
    long long rr = 1000000000000000000LL + 1;

    // Perform binary search to find the maximum value x
    while (ll + 1 < rr) {
        // Calculate the mid-point of the current bounds
        long long x = (ll + rr) / 2;
        long long tot = 0;  // Initialize the total count of valid pairs

        // Iterate through each element in the sorted list A
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {  // If the current element is negative
                int l = -1;
                int r = N;
                // Perform binary search to find the count of elements that can form a valid pair with A[i]
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {  // Check if the product is less than x
                        r = c;  // Move the right bound down
                    } else {
                        l = c;  // Move the left bound up
                    }
                }
                // Count how many elements can form a valid pair with A[i]
                tot += N - r;
            } else {  // If the current element is non-negative
                int l = -1;
                int r = N;
                // Perform binary search to find the count of elements that can form a valid pair with A[i]
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {  // Check if the product is less than x
                        l = c;  // Move the left bound up
                    } else {
                        r = c;  // Move the right bound down
                    }
                }
                // Count how many elements can form a valid pair with A[i]
                tot += r;
            }

            // Adjust the total count if A[i] forms a pair with itself
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }

        // Since each pair (i, j) is counted twice, divide the total count by 2
        tot /= 2;

        // Adjust the binary search bounds based on the total count of pairs
        if (tot < K) {
            ll = x;  // If the count is less than K, move the lower bound up
        } else {
            rr = x;  // If the count is at least K, move the upper bound down
        }
    }

    // Print the final result, which is the largest x found
    printf("%lld\n", ll);

    // Free allocated memory
    free(A);

    return 0;
}

// <END-OF-CODE>
