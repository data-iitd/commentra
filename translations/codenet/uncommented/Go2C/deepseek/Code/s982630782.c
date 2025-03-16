#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

void scan(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N = readInt();
    int M = readInt();
    int *A = (int*)malloc(N * sizeof(int));
    scan(A, N);

    int *counts = (int*)calloc(M * 2, sizeof(int));
    for (int i = 0; i < M; i++) {
        counts[i * 2] = readInt();
        counts[i * 2 + 1] = readInt();
    }

    for (int i = 0; i < M; i++) {
        counts[counts[i * 2 + 1] - 1] += counts[i * 2];
    }

    qsort(A, N, sizeof(int), compare);
    qsort(counts, M * 2, sizeof(int), compare);

    int sum = 0;
    int rest = N;
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (j < M * 2 && A[i] < counts[M * 2 - 1 - j]) {
            sum += counts[M * 2 - 1 - j];
            j++;
            rest--;
            if (rest == 0) break;
        } else {
            sum += A[i];
        }
    }

    printf("%d\n", sum);

    free(A);
    free(counts);
    return 0;
}
