#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} shop;

int compare(const void *p1, const void *p2) {
    shop *s1 = (shop *)p1;
    shop *s2 = (shop *)p2;
    return s1->a - s2->a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    shop s[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }
    qsort(s, N, sizeof(shop), compare);

    int total = 0;
    for (int i = 0; i < N; i++) {
        int n = min(s[i].b, M);
        total += n * s[i].a;
        M -= n;
        if (M == 0) {
            break;
        }
    }
    printf("%d\n", total);
    return 0;
}

