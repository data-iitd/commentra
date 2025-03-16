#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(long long*)b - *(long long*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    long long A[N];
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }
    qsort(A, N, sizeof(long long), compare);
    int index;
    long long max = 1e9 + 7;
    for(int i = 1; i < N; ++i) {
        if(max > abs(A[0] - 2 * A[i])) {
            max = abs(A[0] - 2 * A[i]);
            index = i;
        }
    }
    printf("%lld %lld\n", A[0], A[index]);
}
