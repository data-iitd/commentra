
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, c, f;
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    f = 1;
    c = 0;
    qsort(l, n, sizeof(int));
    for (i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;
        }
    }
    printf("%d\n", c + 1);
    free(l);
    return 0;
}

