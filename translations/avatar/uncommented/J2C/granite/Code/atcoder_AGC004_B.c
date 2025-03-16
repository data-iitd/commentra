
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, i, j;
    long x, *srimeList, *costList, minCost;

    scanf("%d %ld", &N, &x);
    srimeList = (long*)malloc(sizeof(long) * N);
    costList = (long*)malloc(sizeof(long) * N);

    for (i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    for (i = 0; i < N; i++) {
        costList[i] = srimeList[i];
        for (j = 1; j < N; j++) {
            costList[i] = costList[i] < srimeList[(i - j + N) % N]? costList[i] : srimeList[(i - j + N) % N];
        }
    }

    minCost = LLONG_MAX;
    for (i = 0; i < N; i++) {
        minCost = minCost < i * x + costList[i]? minCost : i * x + costList[i];
    }

    printf("%ld\n", minCost);

    free(srimeList);
    free(costList);

    return 0;
}
