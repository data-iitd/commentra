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
    
    int hp[n + 1];
    for (int i = 0; i < n; i++) {
        hp[p[i]] = h[i];
    }
    
    int path[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            path[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][b] = 1;
        path[b][a] = 1;
    }
    
    int c = 0;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (path[i][j] == 1 && hp[i] <= hp[j]) {
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
