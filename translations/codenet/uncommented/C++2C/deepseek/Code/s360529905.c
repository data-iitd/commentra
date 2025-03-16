#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int *a, *b, i, N;
    int frontHalf, backHalf;
    scanf("%d", &N);
    a = (int*)malloc(N * sizeof(int));
    b = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    qsort(b, N, sizeof(int), compare);
    frontHalf = b[N / 2 - 1];
    backHalf = b[N / 2];
    free(b);
    for (i = 0; i < N; i++) {
        if (a[i] < backHalf)
            printf("%d\n", backHalf);
        else
            printf("%d\n", frontHalf);
    }
    free(a);
    return 0;
}
