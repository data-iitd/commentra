#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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

    int r[n];
    for (int i = 0; i < n; ++i) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }

    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[i] = 1;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[i] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (r[i] == 1) {
            ++count;
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < n; ++i) {
        if (r[i] == 1) {
            printf("%d %d\n", i + 1, i + 2);
        }
    }

    return 0;
}

