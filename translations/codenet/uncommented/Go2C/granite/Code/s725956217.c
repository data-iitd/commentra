
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} shop;

int cmpfunc (const void * a, const void * b) {
   return ((shop*)a)->a - ((shop*)b)->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    shop s[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }

    qsort(s, N, sizeof(shop), cmpfunc);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = (s[i].b < M)? s[i].b : M;
        total += n * s[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    printf("%d\n", total);

    return 0;
}
