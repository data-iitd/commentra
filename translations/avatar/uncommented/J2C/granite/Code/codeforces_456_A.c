
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, temp, q, w, e, f;
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    temp = a[0];
    q = b[0];
    f = 0;
    if (temp < a[0]) {
        if (q > b[0]) {
            f = 1;
        }
        q = b[0];
        temp = a[0];
    }
    if (temp > a[0]) {
        if (q < b[0]) {
            f = 1;
        }
        q = b[0];
        temp = a[0];
    }
    if (a[0] > w) {
        w = a[0];
        if (b[0] < e) {
            f = 1;
        }
        e = b[0];
    }
    if (a[0] < w) {
        if (b[0] > e) {
            f = 1;
        }
    }
    for (i = 1; i < n; i++) {
        temp = a[i];
        if (temp < a[i]) {
            if (q > b[i]) {
                f = 1;
            }
            q = b[i];
            temp = a[i];
        }
        if (temp > a[i]) {
            if (q < b[i]) {
                f = 1;
            }
            q = b[i];
            temp = a[i];
        }
        if (a[i] > w) {
            w = a[i];
            if (b[i] < e) {
                f = 1;
            }
            e = b[i];
        }
        if (a[i] < w) {
            if (b[i] > e) {
                f = 1;
            }
        }
    }
    if (f == 1) {
        printf("Happy Alex");
    } else {
        printf("Poor Alex");
    }
    return 0;
}
