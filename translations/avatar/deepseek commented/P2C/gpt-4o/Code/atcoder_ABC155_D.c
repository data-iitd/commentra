#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K); // Reading N and K
    long long *A = (long long *)malloc(N * sizeof(long long)); // Allocating memory for list A
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &A[i]); // Reading list A
    }
    
    qsort(A, N, sizeof(long long), compare); // Sorting the list A

    long long ll = -1000000000000000000LL - 1; // Lower limit initialized to a very small number
    long long rr = 1000000000000000000LL + 1; // Upper limit initialized to a very large number

    // Binary search execution
    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2; // Calculating the midpoint of the current range
        long long tot = 0; // Initializing the total count of valid pairs
        
        // Counting valid pairs for each element in A
        for (long long i = 0; i < N; i++) {
            if (A[i] < 0) {
                long long l = -1;
                long long r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r; // Updating the total count for negative A[i]
            } else {
                long long l = -1;
                long long r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
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
    free(A); // Freeing allocated memory
    return 0;
} // <END-OF-CODE>
