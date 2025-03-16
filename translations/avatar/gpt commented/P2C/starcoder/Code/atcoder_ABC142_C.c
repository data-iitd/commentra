#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int A_[N];
    for (int i = 0; i < N; i++) {
        A_[i] = A[i];
    }
    qsort(A_, N, sizeof(int), (int (*)(const void *, const void *))compare);
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A_[i]);
    }
    printf("%d", A_[N - 1]);
    return 0;
}

