
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int B[N];
    for (int i = 0; i < N; i++) {
        B[i] = i + 1;
    }

    qsort(B, N, sizeof(int), cmpfunc);

    for (int i = 0; i < N; i++) {
        printf("%d ", B[i]);
    }

    return 0;
}
