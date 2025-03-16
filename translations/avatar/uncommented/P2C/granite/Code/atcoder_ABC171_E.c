
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    int *a = (int *)malloc(N * sizeof(int));
    int total = 0;
    for (int i = 0; i < N; i++) {
        a[i] = atoi(argv[i + 2]);
        total ^= a[i];
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i] ^ total);
    }
    printf("\n");
    free(a);
    return 0;
}
