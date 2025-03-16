#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int as[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    qsort(as, n, sizeof(int), compare);

    int xs[MAX_N];
    int size = 0;
    for (int i = 0; i < n; i++) {
        int pos = (int)(bsearch(&as[i], xs, size, sizeof(int), compare) - xs);
        if (pos == size) {
            xs[size++] = as[i];
        } else {
            xs[pos] = as[i];
        }
    }

    printf("%d\n", size);
    return 0;
}
