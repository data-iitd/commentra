#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(long long*)b - *(long long*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    long long A[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }
    qsort(A, N, sizeof(long long), compare);
    int index;
    long long max = LLONG_MAX;
    for (int i = 1; i < N; ++i) {
        long long diff = abs(A[0] - 2 * A[i]);
        if (max > diff) {
            max = diff;
            index = i;
        }
    }
    printf("%lld %lld\n", A[0], A[index]);
}

