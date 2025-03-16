#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), compare);

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i-1];
    }

    printf("%d\n", ans);

