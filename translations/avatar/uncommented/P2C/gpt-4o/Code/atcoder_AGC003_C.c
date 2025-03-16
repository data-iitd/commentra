#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        A[i] = input * N + i;
    }
    
    qsort(A, N, sizeof(int), compare);
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int d = (A[i] % N) % 2;
        if (d % 2 != i % 2) {
            cnt++;
        }
    }
    
    printf("%d\n", cnt / 2);
    
    free(A);
    return 0;
}

// <END-OF-CODE>
