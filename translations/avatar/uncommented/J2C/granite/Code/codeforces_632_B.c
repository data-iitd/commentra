
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    char s[100001];
    scanf("%s", s);
    long long sum = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'B') {
            sum += a[i];
        }
    }
    long long ans = sum;
    long long sum1 = sum;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        ans = ans > sum1? ans : sum1;
    }
    sum1 = sum;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        ans = ans > sum1? ans : sum1;
    }
    printf("%lld\n", ans);
    return 0;
}
// END-OF-CODE