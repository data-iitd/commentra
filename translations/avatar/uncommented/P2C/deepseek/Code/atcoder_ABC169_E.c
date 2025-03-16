#include <stdio.h>
#include <stdlib.h>

void resolve() {
    int n;
    scanf("%d", &n);
    int low[n], high[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        low[i] = a;
        high[i] = b;
    }
    qsort(low, n, sizeof(int), (int (*)(const void *, const void *))compare);
    qsort(high, n, sizeof(int), (int (*)(const void *, const void *))compare);
    if (n % 2) {
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    } else {
        double hh = (high[(n) / 2 - 1] + high[(n) / 2]) / 2.0;
        double ll = (low[(n) / 2 - 1] + low[(n) / 2]) / 2.0;
        printf("%d\n", (int)((hh - ll) * 2) + 1);
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    resolve();
    return 0;
}
