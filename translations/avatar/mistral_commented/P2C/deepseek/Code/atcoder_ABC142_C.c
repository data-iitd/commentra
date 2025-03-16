#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[1] - y[1];
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }

    qsort(A, N, sizeof(int) * 2, compare);

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i][0]);
    }
    printf("%d\n", A[N - 1][0]);

    return 0;
}
