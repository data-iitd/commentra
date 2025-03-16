#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int X[N], Y[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }

    qsort(Y, N, sizeof(int), compare);

    int y = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] < y) {
            printf("%d\n", Y[N / 2]);
        } else {
            printf("%d\n", Y[N / 2 - 1]);
        }
    }

    return 0;
}
