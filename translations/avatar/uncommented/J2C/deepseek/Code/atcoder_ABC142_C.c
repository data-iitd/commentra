#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    int *idorder = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        idorder[A[i] - 1] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", idorder[i]);
    }

    free(A);
    free(idorder);
    return 0;
}
