
#include <stdio.h>

int main() {
    int N, A[100000], mn = N + 1, mx = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (i + 1!= A[i]) {
            mn = mn < i? mn : i;
            mx = mx > i? mx : i;
        }
    }
    if (mx == -1) {
        printf("0 0\n");
    } else {
        for (int i = mn; i <= (mn + mx) / 2; i++) {
            int temp = A[i];
            A[i] = A[mn + mx - i];
            A[mn + mx - i] = temp;
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
