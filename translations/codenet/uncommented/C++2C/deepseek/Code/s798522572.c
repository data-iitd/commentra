#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    int A[N];
    int *B = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int m = A[0];
    B[0] = A[1] - m;
    m = (m < A[1]) ? m : A[1];
    for (int i = 2; i < N; i++) {
        B[i] = A[i] - m;
        m = (m < A[i]) ? m : A[i];
    }
    int max_value = B[0];
    for (int i = 1; i < N; i++) {
        if (B[i] > max_value) {
            max_value = B[i];
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] == max_value) {
            count++;
        }
    }
    printf("%d\n", count);
    free(B);
    return 0;
}
