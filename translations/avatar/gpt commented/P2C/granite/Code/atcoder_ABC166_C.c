
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, a, b, c = 0;
    scanf("%d %d", &n, &m);
    int *p = (int *)malloc(n * sizeof(int));
    int *h = (int *)malloc(n * sizeof(int));
    int **path = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        path[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        path[a - 1][b - 1] = 1;
        path[b - 1][a - 1] = 1;
    }
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
    printf("%d", c);
    return 0;
}
