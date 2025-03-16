#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int m = 0;

    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    int r[n * (n - 1) / 2][2];
    int k = 0;

    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r[k][0] = m + 1;
            r[k][1] = i + 1;
            ++k;
        }
    }

    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[k][0] = i;
            r[k][1] = i + 1;
            ++k;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[k][0] = i;
            r[k][1] = i - 1;
            ++k;
        }
    }

    printf("%d\n", k);
    for (int i = 0; i < k; ++i) {
        printf("%d %d\n", r[i][0], r[i][1]);
    }

    return 0;
}
