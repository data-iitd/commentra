#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *h = (int *)malloc(n * sizeof(int));
    int *good = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        good[i] = 1; // true
    }
    
    for (int i = 0; i < m; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        ai--; // Convert to 0-based index
        bi--; // Convert to 0-based index
        
        if (h[ai] > h[bi]) {
            good[bi] = 0; // false
        } else if (h[ai] < h[bi]) {
            good[ai] = 0; // false
        } else {
            good[ai] = 0; // false
            good[bi] = 0; // false
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    
    free(h);
    free(good);
    
    return 0;
}

// <END-OF-CODE>
