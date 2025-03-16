#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
<<<<<<< HEAD
    int *X = (int*)malloc(N * sizeof(int));
    int *Y = (int*)malloc(N * sizeof(int));
=======
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
>>>>>>> 98c87cb78a (data updated)

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }

    qsort(Y, N, sizeof(int), compare);

    int y = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] < Y[N / 2]) {
            printf("%d\n", Y[N / 2]);
        } else {
            printf("%d\n", Y[N / 2 - 1]);
        }
    }

    free(X);
    free(Y);
    return 0;
}

// <END-OF-CODE>
