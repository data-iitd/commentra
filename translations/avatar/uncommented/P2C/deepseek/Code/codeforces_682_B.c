#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, c = 0, f = 1;
    scanf("%d", &n);
    int* l = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), (int (*)(const void*, const void*))compare);
    for (i = 0; i < n; i++) {
        if (l[i] > c) {
            c += 1;
        }
    }
    printf("%d\n", c + 1);
    free(l);
    return 0;
}

int compare(const int* a, const int* b) {
    return (*a - *b);
}
