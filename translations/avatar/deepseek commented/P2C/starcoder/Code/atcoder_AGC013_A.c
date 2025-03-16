#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int i = 1;
    int ans = 0;
    while (i < N - 1) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans += 1;
            i += 1;
        }
        i += 1;
    }
    printf("%d", ans + 1);
    return 0;
}

