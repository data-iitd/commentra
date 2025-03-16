#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x;
    scanf("%d %ld", &N, &x);

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
            int index = (i - castNum + N) % N;
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[index]) ? costList[i][castNum - 1] : srimeList[index];
        }
    }

    long *result = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += costList[j][i];
        }
        result[i] = i * x + sum;
    }

    long min = LONG_MAX;
    for (int i = 0; i < N; i++) {
        if (result[i] < min) {
            min = result[i];
        }
    }

    printf("%ld\n", min);

    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    free(srimeList);
    free(result);

    return 0;
}
