#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    char s[n + 1];
    scanf("%s", s);
    
    long sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            sum += a[i];
        }
    }
    
    long ans = sum;
    long sum1 = sum;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        if (sum1 > ans) {
            ans = sum1;
        }
    }
    
    sum1 = sum;
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        if (sum1 > ans) {
            ans = sum1;
        }
    }
    
    printf("%ld\n", ans);
    
    return 0;
}
