#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);
    
    long sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (ch == 'B') {
            sum += a[i];
        }
    }
    
    long ans = sum;
    long sum1 = sum;
    
    for (int i = 0; i < strlen(s); i++) {
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
    for (int i = strlen(s) - 1; i >= 0; i--) {
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

// <END-OF-CODE>
