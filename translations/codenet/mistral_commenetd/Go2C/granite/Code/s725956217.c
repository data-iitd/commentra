
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} shop;

typedef struct {
    int len;
    shop *shops;
} Datas;

int cmpfunc (const void * a, const void * b) {
   return ((shop*)a)->a - ((shop*)b)->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Datas s;
    s.len = N;
    s.shops = (shop*)malloc(N * sizeof(shop));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s.shops[i].a, &s.shops[i].b);
    }
    qsort(s.shops, N, sizeof(shop), cmpfunc);
    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = s.shops[i].b < M? s.shops[i].b : M;
        total += n * s.shops[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    printf("%d\n", total);
    free(s.shops);
    return 0;
}
