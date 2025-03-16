#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;
    }
    
    long long res = 0;
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);
    }
    
    printf("%lld\n", res);
    
    free(a);
    free(b);
    
    return 0;
}

// <END-OF-CODE>
