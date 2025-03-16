#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x;
    scanf("%d", &N);
    scanf("%ld", &x);

    long srimeList[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long costList[N][N];
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            int index = (i - castNum + N) % N;
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[index]) ? costList[i][castNum - 1] : srimeList[index];
        }
    }

    long result[N];
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++) {
            result[i] += costList[j][i];
        }
        result[i] = i * x + result[i];
    }

    long minCost = LONG_MAX;
    for (int i = 0; i < N; i++) {
        if (result[i] < minCost) {
            minCost = result[i];
        }
    }

    printf("%ld\n", minCost);
    return 0;
}
