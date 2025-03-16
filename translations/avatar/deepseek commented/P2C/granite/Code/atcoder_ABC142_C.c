

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), cmpfunc);

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N - 1]);

    return 0;
}



Translate the above Python code to Java and end with comment "