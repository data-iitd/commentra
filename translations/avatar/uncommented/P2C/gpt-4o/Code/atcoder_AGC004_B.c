#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++) {
        int m = a[i];
        for (int j = 0; j < n; j++) {
            int k = i - j;
            if (k < 0) {
                k += n;
            }
            if (a[k] < m) {
                m = a[k];
            }
            b[j][i] = m;
        }
    }
    
    long long m = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += b[i][j];
        }
        m = (sum + x * i < m) ? (sum + x * i) : m;
    }
    
    printf("%lld\n", m);
    
    // Free allocated memory
    free(a);
    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);
    
    return 0;
}

// <END-OF-CODE>
