#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->value - ((Element *)b)->value;
}

int main() {
    int N;
    scanf("%d", &N);
    
    Element *A = (Element *)malloc(N * sizeof(Element));
    
    for (int i = 0; i < N; i++) {
        A[i].index = i + 1;
        scanf("%d", &A[i].value);
    }
    
    qsort(A, N, sizeof(Element), compare);
    
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i].index);
    }
    printf("%d\n", A[N - 1].index);
    
    free(A);
    return 0;
}

// <END-OF-CODE>
