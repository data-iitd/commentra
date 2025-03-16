#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int mn = N + 1, mx = -1;
    for (int i = 0; i < N; i++) {
        if (i + 1 != A[i]) {
            if (mn > i) mn = i;
            if (mx < i) mx = i;
        }
    }

    if (mx == -1) {
        printf("0 0\n");
    } else {
        // Reverse the segment A[mn] to A[mx]
        for (int j = mn, k = mx; j < k; j++, k--) {
            int temp = A[j];
            A[j] = A[k];
            A[k] = temp;
        }

        // Check if the array is sorted
        int isSorted = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i - 1]) {
                isSorted = 0;
                break;
            }
        }

        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }

    free(A);
    return 0;
}

// <END-OF-CODE>
