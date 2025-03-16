
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
            mn = mn < i? mn : i;
            mx = mx > i? mx : i;
        }
    }
    if (mx == -1) {
        printf("0 0\n");
    } else {
        for (int i = mn; i < (mx + 1) / 2; i++) {
            int temp = A[i];
            A[i] = A[mx + 1 - i];
            A[mx + 1 - i] = temp;
        }
        int flag = 1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d %d\n", mn + 1, mx + 1);
        } else {
            printf("0 0\n");
        }
    }
    return 0;
}
