#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int q = n / m;
    int r = n % m;
    int a[m];
    
    for (int i = 0; i < m; i++) {
        a[i] = q;
    }
    
    for (int i = 0; i < r; i++) {
        a[i]++;
    }
    
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
