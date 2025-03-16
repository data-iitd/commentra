#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))

int main() {
    // Read the number of elements N
    int N;
    scanf("%d", &N);
    
    // Read N integers into an array `a`
    int *a = (int *)malloc(N * sizeof(int));
    REP(i, N) scanf("%d", &a[i]);

    // Initialize idx to 1 and ans to 0
    int idx = 1;
    int ans = 0;

    // Iterate through the array `a`
    REP(i, N) {
        // If the current element is equal to `idx`, increment `idx`
        if (a[i] == idx) {
            idx++;
        } else {
            // If not, increment `ans`
            ans++;
        }
    }

    // If `idx` is still 1, it means no elements matched, so print `-1`
    if (idx == 1) {
        printf("-1\n");
    } else {
        // Otherwise, print `ans`
        printf("%d\n", ans);
    }

    // Free the allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
