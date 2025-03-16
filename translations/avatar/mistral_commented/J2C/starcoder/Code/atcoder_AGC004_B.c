#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 1000000

int main() {
    int N;
    long x;
    scanf("%d %ld", &N, &x);

    long srimeList[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long costList[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    long result[MAX_N];
    for (int i = 0; i < N; i++) {
        long temp = i * x;
        for (int cost = 0; cost < N; cost++) {
            temp += costList[i][cost];
        }
        result[i] = temp;
    }

    printf("%ld\n", *min_element(result, result + N));

    return 0;
}

