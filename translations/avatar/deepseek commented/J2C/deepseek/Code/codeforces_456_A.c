#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int main() {
    int n;
    int a[MAX_N], b[MAX_N];
    int temp = 0, q = 0, w = 0, e = 0;
    int i;
    char f = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
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

    if (f) {
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }

    return 0;
}
