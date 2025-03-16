#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }

    qsort(A, N, sizeof(int), compare);

    int min = A[0];
    int max = A[N - 1];

    long mins = 0;
    long maxs = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == min) mins++;
        if (A[i] == max) maxs++;
    }

    if (min == max) {
        printf("%d %ld\n", (max - min), mins * (mins - 1) / 2);
    } else {
        printf("%d %ld\n", (max - min), mins * maxs);
    }

    return 0;
}
