#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int readInt() {
    int num = 0, ch;
    while ((ch = getchar_unlocked()) >= '0' && ch <= '9')
        num = num * 10 + ch - '0';
    return num;
}

int main() {
    int n = readInt();
    int m = readInt();

    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }

    long long ans = 0;
    int base = 0;
    int dp[MAX_N + 1] = {0};

    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        dp[(base + a[i] % m) % m]++;
        ans += dp[base];
    }

    printf("%lld\n", ans);
    return 0;
}

