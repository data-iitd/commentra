#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    int **path = (int **)malloc((n + 1) * sizeof(int *));
    int *path_size = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        path[i] = (int *)malloc(n * sizeof(int));
        path_size[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        path[a][path_size[a]++] = b;
        path[b][path_size[b]++] = a;
    }
    
    int c = 0;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 0; j < path_size[i]; j++) {
            int neighbor = path[i][j];
            if (h[i - 1] <= h[neighbor - 1]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            c++;
        }
    }
    
    printf("%d\n", c);
    
    // Free allocated memory
    for (int i = 1; i <= n; i++) {
        free(path[i]);
    }
    free(path);
    free(path_size);
    free(p);
    free(h);
    
    return 0;
}

// <END-OF-CODE>
