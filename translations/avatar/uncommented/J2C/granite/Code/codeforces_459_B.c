
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }
    qsort(A, N, sizeof(int));
    int min = A[0];
    int max = A[N - 1];
    long mins = 0;
    long maxs = 0;
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }
    if (min == max) {
        printf("%ld %ld\n", (long)(max - min), mins * (mins - 1) / 2);
    } else {
        printf("%ld %ld\n", (long)(max - min), mins * maxs);
    }
    return 0;
}

