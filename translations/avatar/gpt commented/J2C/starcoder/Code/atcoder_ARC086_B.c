#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }
    int r[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r[j++] = m + 1;
            r[j++] = i + 1;
        }
    }
    if (a[m] >= 0) {
        for (int i = 1; i < n; i++) {
            r[j++] = i;
            r[j++] = i + 1;
        }
    } else {
        for (int i = n; i > 1; i--) {
            r[j++] = i;
            r[j++] = i - 1;
        }
    }
    printf("%d\n", j);
    for (int i = 0; i < j; i++) {
        printf("%d %d\n", r[i], r[i + 1]);
    }
    return 0;
}

