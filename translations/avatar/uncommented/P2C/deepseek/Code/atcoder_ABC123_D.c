#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, k;
    scanf("%d %d %d %d", &x, &y, &z, &k);

    int a[x], b[y], c[z];
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < z; i++) {
        scanf("%d", &c[i]);
    }

    int ab[x * y];
    int ab_index = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab[ab_index++] = a[i] + b[j];
        }
    }

    qsort(ab, ab_index, sizeof(int), (int (*)(const void *, const void *))compare);
    int abc[k];
    int abc_index = 0;
    for (int i = 0; i < (x * y) && i < k; i++) {
        for (int j = 0; j < z; j++) {
            abc[abc_index++] = ab[i] + c[j];
        }
    }

    qsort(abc, abc_index, sizeof(int), (int (*)(const void *, const void *))compare);
    for (int i = 0; i < k; i++) {
        printf("%d\n", abc[i]);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
