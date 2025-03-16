#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int check(int n, int* x, int* y, int* h, int cx, int cy) {
    int ch = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (h[i] != (ch - abs(x[i] - cx) - abs(y[i] - cy) > 0 ? ch - abs(x[i] - cx) - abs(y[i] - cy) : 0)) {
            return -1;
        }
    }
    return ch;
}

int main() {
    int n;
    scanf("%d", &n);
    int x[n], y[n], h[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            int ch = check(n, x, y, h, i, j);
            if (ch > 0) {
                printf("%d %d %d\n", i, j, ch);
            }
        }
    }

    return 0;
}
