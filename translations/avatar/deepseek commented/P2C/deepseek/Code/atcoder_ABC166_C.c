#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int p[n];
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    int h[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int path[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            path[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a - 1][b - 1] = 1;
        path[b - 1][a - 1] = 1;
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 1 && h[i] <= h[j]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            c++;
        }
    }

    printf("%d\n", c);

    return 0;
}
