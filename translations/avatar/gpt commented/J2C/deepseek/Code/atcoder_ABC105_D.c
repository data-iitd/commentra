#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int readInt() {
    int num = 0, ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        num = num * 10 + (ch - '0');
    }
    return num;
}

int readIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
    return 0;
}

void solve(int n, int m, int *a) {
    int dp[MAX_N] = {0};
    long long ans = 0;
    int base = 0;

    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        dp[(base + a[i]) % m]++;
        ans += dp[base];
    }

    printf("%lld\n", ans);
}

int main() {
    int n = readInt();
    int m = readInt();
    int a[MAX_N];
    readIntArray(a, n);
    solve(n, m, a);
    return 0;
}
