#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairA->value - pairB->value;
}

int main() {
    int N;
    scanf("%d", &N);

    Pair A[N];
    for (int i = 0; i < N; i++) {
        A[i].index = i + 1;
        scanf("%d", &A[i].value);
    }

    qsort(A, N, sizeof(Pair), compare);

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", A[i].index);
    }
    printf("%d\n", A[N - 1].index);

    return 0;
}
