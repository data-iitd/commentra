
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int r;
    int c;
} TSize;

typedef struct {
    int** data;
    int size;
} TMatrix;

int Count(TSize left, TSize right) {
    return left.r * right.c * left.c;
}

int Solve(TMatrix* memo, int s, int l) {
    if (s == l) {
        return 0;
    }
    if (memo->data[s][l]!= 0) {
        return memo->data[s][l];
    }
    int min = INT_MAX;
    for (int i = s; i < l; i++) {
        int c = Solve(memo, s, i) + Count((TSize){memo->data[s][0], memo->data[s][1]}, (TSize){memo->data[i+1][0], memo->data[l][1]}) + Solve(memo, i+1, l);
        if (c < min) {
            min = c;
        }
    }
    memo->data[s][l] = min;
    return min;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    TMatrix chain = {malloc(n * sizeof(int *)), n};
    for (int i = 0; i < n; i++) {
        chain.data[i] = malloc(2 * sizeof(int));
        scanf("%d %d", &chain.data[i][0], &chain.data[i][1]);
    }
    TMatrix memo = {malloc(n * n * sizeof(int)), n};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            memo.data[i][j] = 0;
        }
    }
    int result = Solve(&memo, 0, n-1);
    printf("%d\n", result);
    for (int i = 0; i < n; i++) {
        free(chain.data[i]);
    }
    free(chain.data);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            memo.data[i][j] = 0;
        }
    }
    free(memo.data);
    return 0;
}
