#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int num = 998244353;
    int n;
    scanf("%d", &n);
    int ai[n], bi[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ai[i], &bi[i]);
    }

    qsort(ai, n, sizeof(int), compare);
    qsort(bi, n, sizeof(int), compare);

    if (n % 2 == 1) {
        printf("%d\n", bi[n / 2] - ai[n / 2] + 1);
    } else {
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        printf("%d\n", (int)(2 * (c - b) + 1));
    }

    return 0;
}

