#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(long long *)b - *(long long *)a);
}

int main() {
    int N;
    scanf("%d", &N);
    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &A[i]);
    }
    
    qsort(A, N, sizeof(long long), compare);
    
    int index = 0;
    long long max = 1000000007; // inf
    for (int i = 1; i < N; ++i) {
        long long diff = llabs(A[0] - 2 * A[i]);
        if (max > diff) {
            max = diff;
            index = i;
        }
    }
    
    printf("%lld %lld\n", A[0], A[index]);
    
    free(A);
    return 0;
}

// <END-OF-CODE>
