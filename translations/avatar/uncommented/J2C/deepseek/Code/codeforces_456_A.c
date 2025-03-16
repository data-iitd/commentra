#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    int temp = 0;
    int q = 0;
    int w = 0, e = 0;
    int f = 0;

    for (int i = 0; i < n; i++) {
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

    if (f == 1) {
        printf("Happy Alex\n");
    } else {
        printf("Poor Alex\n");
    }

    return 0;
}
