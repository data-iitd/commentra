#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return y[0] - x[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int m[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i][0], &m[i][1]);
    }

    qsort(m, n, sizeof(m[0]), compare);

    int *a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {
            printf("Happy Alex\n");
            return 0;
        }
        a = m[i];
    }
    printf("Poor Alex\n");

    return 0;
}
