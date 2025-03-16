#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *X = (int *)malloc(N * sizeof(int));
    int *Y = (int *)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }
    
    qsort(Y, N, sizeof(int), compare);
    
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2);
        } else {
            printf("%d\n", m1);
        }
    }
    
    free(X);
    free(Y);
    
    return 0;
}

// <END-OF-CODE>
