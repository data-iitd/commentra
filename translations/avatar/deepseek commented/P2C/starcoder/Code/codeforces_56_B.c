
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int mn = N + 1, mx = -1;
    for (int i = 0; i < N; i++) {
        if (i + 1!= A[i]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    if (mx == -1) {
        printf("0 0\n");
    } else {
        for (int i = mn; i <= mx; i++) {
            A[i] = A[mx + mn - i];
        }
        if (is_sorted(A, N)) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }

    return 0;
}

