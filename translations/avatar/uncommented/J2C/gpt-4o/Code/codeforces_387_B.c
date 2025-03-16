#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *req = (int *)malloc(n * sizeof(int));
    int *pre = (int *)malloc(m * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &pre[i]);
    }
    
    int i = n - 1, j = m - 1;
    int ans = 0;
    
    while (i >= 0 && j >= 0) {
        if (req[i] > pre[j]) {
            ans++;
        } else {
            j--;
        }
        i--;
    }
    
    printf("%d\n", ans + i + 1);
    
    free(req);
    free(pre);
    
    return 0;
}

// <END-OF-CODE>
