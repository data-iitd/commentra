#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
    int a;
    int b;
} Pair;

int compare_pairs(const void *p1, const void *p2) {
    Pair *pair1 = (Pair *)p1;
    Pair *pair2 = (Pair *)p2;
    return (pair1->a - pair2->a);
}

int main() {
    int n;
    Pair pairs[MAX_N];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pairs[i].a, &pairs[i].b);
    }

    qsort(pairs, n, sizeof(Pair), compare_pairs);

    for (int i = 0; i < n - 1; i++) {
        if (pairs[i].b > pairs[i + 1].b) {
            printf("Happy Alex\n");
            return 0;
        }
    }

    printf("Poor Alex\n");
    return 0;
}

