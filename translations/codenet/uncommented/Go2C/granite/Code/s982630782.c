
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *a = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int *b = (int *)malloc(sizeof(int) * M);
    int *c = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &b[i], &c[i]);
    }
    int *d = (int *)malloc(sizeof(int) * (N + M));
    memcpy(d, a, sizeof(int) * N);
    memcpy(d + N, c, sizeof(int) * M);
    qsort(d, N + M, sizeof(int), cmpfunc);
    int sum = 0;
    int rest = N;
    for (int i = N + M - 1; i >= 0; i--) {
        if (rest == 0) {
            break;
        }
        if (b[i] >= rest) {
            sum += rest * d[i];
            rest = 0;
        } else {
            sum += b[i] * d[i];
            rest -= b[i];
        }
    }
    printf("%d\n", sum);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

