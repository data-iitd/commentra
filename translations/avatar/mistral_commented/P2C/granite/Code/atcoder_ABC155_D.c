
###
# Code
###

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define input variables
    int N, K;
    scanf("%d %d", &N, &K);

    // Initialize array 'A' with input values
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Sort array 'A' in ascending order
    qsort(A, N, sizeof(int), cmpfunc);

    // Initialize variables for binary search
    long long ll = -100000000000000000LL - 1;
    long long rr = 100000000000000000LL + 1;

    // Perform binary search until 'll + 1' is less than 'rr'
    while (ll + 1 < rr) {
        // Calculate mid value for binary search
        long long x = (ll + rr) / 2;

        // Initialize variable 'tot' to store total count of elements
        int tot = 0;

        // Iterate through array 'A' and calculate total count of elements that satisfy the condition
        for (int i = 0; i < N; i++) {
            // Check if current element 'A[i]' is negative
            if (A[i] < 0) {
                // Initialize variables 'l' and 'r' for binary search in the range of indices
                int l = 0, r = N;

                // Perform binary search to find the index 'c' such that A[i] * A[c] >= x
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }

                // Update 'tot' with the number of elements greater than 'c'
                tot += N - r;
            } else {
                // Perform similar binary search and update 'tot' accordingly
                int l = 0, r = N;
                while (l + 1 < r) {
                    int c = (l + r) / 2;
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
                tot--;
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

    return 0;
}

