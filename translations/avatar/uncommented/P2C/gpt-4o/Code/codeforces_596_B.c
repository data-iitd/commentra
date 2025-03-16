#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int r[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    
    long long ans = abs(r[0]);
    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i - 1]);
    }
    
    printf("%lld\n", ans);
    return 0;
}

// <END-OF-CODE>
