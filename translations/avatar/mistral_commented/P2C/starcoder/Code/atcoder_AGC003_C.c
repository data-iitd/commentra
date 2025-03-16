#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = (int) (scanf("%d", &N) * N + i);
    }
    qsort(A, N, sizeof(int), compare);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2!= i % 2) {
            cnt++;
        }
    }
    printf("%d", cnt / 2);
    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

