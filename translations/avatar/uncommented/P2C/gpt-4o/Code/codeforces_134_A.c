#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int w[n];
    long long x = 0; // Use long long to avoid overflow
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x += w[i];
    }
    
    int d[n];
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if ((x - w[i]) / (n - 1) == w[i]) {
            d[count++] = i + 1; // Store 1-based index
        }
    }
    
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d", d[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}

// <END-OF-CODE>
