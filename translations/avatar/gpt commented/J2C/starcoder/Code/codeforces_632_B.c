#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    char s[100000];
    scanf("%s", s);
    long sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'B') {
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
        ans = max(ans, sum1);
    }
    sum1 = sum;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        ans = max(ans, sum1);
    }
    printf("%ld\n", ans);
    return 0;
}
