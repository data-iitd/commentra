#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    int *counter = (int *)calloc(n + 1, sizeof(int)); // Using 1-based indexing
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (h[a - 1] < h[b - 1]) {
            counter[a] = 1;
        } else if (h[a - 1] > h[b - 1]) {
            counter[b] = 1;
        } else {
            counter[a] = 1;
            counter[b] = 1;
        }
    }
    
    int unique_count = 0;
    for (int i = 1; i <= n; i++) {
        if (counter[i] == 0) {
            unique_count++;
        }
    }
    
    printf("%d\n", unique_count);
    
    free(h);
    free(counter);
    return 0;
}
// <END-OF-CODE>
