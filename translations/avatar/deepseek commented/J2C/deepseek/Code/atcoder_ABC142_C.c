#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    int *positions = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        positions[A[i] - 1] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", positions[i]);
    }

    free(A);
    free(positions);

    return 0;
}
