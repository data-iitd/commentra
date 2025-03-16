
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Code for B - Traveling AtCoDeer Problem
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int));

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans += A[i] - A[i-1];
    }

    printf("%d\n", ans);

    return 0;
}
