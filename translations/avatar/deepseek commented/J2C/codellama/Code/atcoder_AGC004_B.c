#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    long x;
    scanf("%d", &N);
    scanf("%ld", &x);

    long *srimeList = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long **costList = (long **)malloc(N * sizeof(long *));
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long));
    }

    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = fmin(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    long *result = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        result[i] = i * x + costList[i][N - 1];
    }

    long minCost = result[0];
    for (int i = 1; i < N; i++) {
        if (result[i] < minCost) {
            minCost = result[i];
        }
    }

    printf("%ld\n", minCost);

    free(srimeList);
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    free(result);

    return 0;
}

