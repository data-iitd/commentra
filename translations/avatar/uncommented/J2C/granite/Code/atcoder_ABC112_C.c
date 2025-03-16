
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int check(int n, int x[], int y[], int h[], int cx, int cy);

int main(void) {
    int n, x[MAX], y[MAX], h[MAX];
    int i, j, ch;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &h[i]);
    }

    for (i = 0; i <= MAX; i++) {
        for (j = 0; j <= MAX; j++) {
            ch = check(n, x, y, h, i, j);
            if (ch > 0) {
                printf("%d %d %d\n", i, j, ch);
            }
        }
    }

    return 0;
}

int check(int n, int x[], int y[], int h[], int cx, int cy) {
    int ch = -1;
    int i;

    for (i = 0; i < n; i++) {
        if (h[i] > 0) {
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (h[i]!= fmax(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1;
        }
    }

    return ch;
}

// 