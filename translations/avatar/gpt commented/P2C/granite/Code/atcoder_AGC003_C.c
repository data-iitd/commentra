
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] = A[i] * N + i;
    }

    qsort(A, N, sizeof(int), cmpfunc);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2!= i % 2) {
            cnt++;
        }
    }

    printf("%d\n", cnt / 2);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

