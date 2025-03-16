
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i][1] > A[j][1]) {
                int temp = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = temp;
            }
        }
    }

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i][0]);
    }
    printf("%d\n", A[N - 1][0]);

    return 0;
}
