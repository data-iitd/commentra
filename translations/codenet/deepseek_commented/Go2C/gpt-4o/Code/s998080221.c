#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }

    printf("%d\n", maxCnt);
    free(A);
    return 0;
}

// <END-OF-CODE>
