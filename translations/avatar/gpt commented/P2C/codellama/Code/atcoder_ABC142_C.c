#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int *A_ = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        A_[i] = A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A_[i] > A_[j]) {
                int temp = A_[i];
                A_[i] = A_[j];
                A_[j] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", A_[i]);
    }

    printf("\n");

    return 0;
}

