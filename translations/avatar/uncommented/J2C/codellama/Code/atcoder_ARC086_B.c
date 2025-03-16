#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int m = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r++;
        }
    }
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r++;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r++;
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", i + 1, (i + 1) % n + 1);
    }
    return 0;
}
