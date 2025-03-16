#include <stdio.h>
#include <stdlib.h>

void debug(long long *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = (dp[i + 1] > a[i]) ? dp[i + 1] : a[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%lld ", (dp[i + 1] - a[i] + 1));
        }
    }
    printf("\n");
    
    free(a);
    free(dp);
    
    return 0;
}

// <END-OF-CODE>
