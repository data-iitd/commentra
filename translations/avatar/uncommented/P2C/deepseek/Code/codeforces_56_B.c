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
        if (i + 1 != A[i]) {
            mn = mn < i ? mn : i;
            mx = mx > i ? mx : i;
        }
    }
    if (mx == -1) {
        printf("0 0\n");
    } else {
        int temp[N];
        for (int i = 0; i < N; i++) {
            temp[i] = A[i];
        }
        for (int i = mn; i <= mx; i++) {
            A[i] = temp[mx - i + mn];
        }
        int sorted = 1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                sorted = 0;
                break;
            }
        }
        if (sorted) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }
    return 0;
}
