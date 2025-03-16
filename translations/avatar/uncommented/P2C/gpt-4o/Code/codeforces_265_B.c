#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    long long ans = n - 1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;
        last = l[i];
    }
    
    printf("%lld\n", ans);
    
    free(l);
    return 0;
}

// <END-OF-CODE>
