#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m, i, j;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int r[n];
    m = 0;
    for (i = 1; i < n; i++) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r[i] = m + 1;
            r[i + 1] = i + 1;
        }
    }

    if (a[m] >= 0) {
        for (i = 1; i < n; i++) {
            r[i] = i + 1;
            r[i + 1] = i + 2;
        }
    } else {
        for (i = n; i > 1; i--) {
            r[i] = i;
            r[i - 1] = i - 1;
        }
    }

    printf("%d\n", n);
    for (i = 0; i < n; i++) {
        printf("%d %d\n", r[i], r[i + 1]);
    }

    return 0;
}

