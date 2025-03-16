#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    int *order = (int *)malloc(N * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        order[A[i] - 1] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", order[i]);
    }

    free(A);
    free(order);
    return 0;
}
