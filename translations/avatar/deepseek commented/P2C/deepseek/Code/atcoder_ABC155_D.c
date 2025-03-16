#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Sorting the array A
    qsort(A, N, sizeof(int), (int (*)(const void *, const void *))compare);

    // Binary search setup
    long long ll = -1e18 - 1; // Lower limit initialized to a very small number
    long long rr = 1e18 + 1;  // Upper limit initialized to a very large number

    // Binary search execution
    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2; // Calculating the midpoint of the current range
        long long tot = 0; // Initializing the total count of valid pairs

        // Counting valid pairs for each element in A
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                int l = -1;
                int r = N;
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r; // Updating the total count for negative A[i]
            } else {
                int l = -1;
                int r = N;
                while (l + 1 < r) {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r; // Updating the total count for non-negative A[i]
            }

            if (A[i] * A[i] < x) {
                tot -= 1; // Adjusting for the pair (i, i) if necessary
            }
        }

        tot /= 2; // Dividing by 2 to correct for double-counting pairs

        // Adjusting the search range based on the total count
        if (tot < K) {
            ll = x;
        } else {
            rr = x;
        }
    }

    printf("%lld\n", ll); // Output the result
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
