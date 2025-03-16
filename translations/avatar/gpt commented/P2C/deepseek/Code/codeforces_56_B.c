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
        if (A[i] != i + 1) {
            mn = (mn < i) ? mn : i;
            mx = (mx > i) ? mx : i;
        }
    }

    if (mx == -1) {
        printf("0 0\n");
    } else {
        int temp;
        for (int i = mn; i <= (mn + mx) / 2; i++) {
            temp = A[i];
            A[i] = A[mn + mx - i];
            A[mn + mx - i] = temp;
        }

        int isSorted = 1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                isSorted = 0;
                break;
            }
        }

        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }

    return 0;
}

