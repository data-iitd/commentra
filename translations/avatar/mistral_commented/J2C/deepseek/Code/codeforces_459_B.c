#include <stdio.h>
#include <stdlib.h>

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
    int mins = 0, maxs = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == min) {
            mins++;
        }
        if (A[i] == max) {
            maxs++;
        }
    }

    if (min == max) {
        long long result = (max - min) + 1;
        result *= mins;
        result -= mins * (mins - 1) / 2;
        printf("%lld\n", result);
    } else {
        long long result = (max - min);
        result *= mins;
        result *= maxs;
        printf("%lld\n", result);
    }

    return 0;
}
