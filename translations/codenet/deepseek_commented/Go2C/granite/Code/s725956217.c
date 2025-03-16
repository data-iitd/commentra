
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} shop;

typedef struct {
    shop *shops;
    int N;
} Datas;

int compare(const void *a, const void *b) {
    shop *s1 = (shop *)a;
    shop *s2 = (shop *)b;
    return s1->a - s2->a;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Datas *datas = (Datas *)malloc(sizeof(Datas));
    datas->shops = (shop *)malloc(sizeof(shop) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &datas->shops[i].a, &datas->shops[i].b);
    }
    datas->N = N;

    qsort(datas->shops, N, sizeof(shop), compare);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = datas->shops[i].b;
        if (n > M) {
            n = M;
        }
        total += datas->shops[i].a * n;
        M -= n;
        if (M == 0) {
            break;
        }
    }

    printf("%d\n", total);

    free(datas->shops);
    free(datas);

    return 0;
}
