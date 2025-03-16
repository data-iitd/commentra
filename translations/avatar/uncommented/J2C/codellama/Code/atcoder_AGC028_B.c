
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modinv(int a, int m) {
    int b = m;
    int u = 1;
    int v = 0;
    int tmp = 0;
    while (b > 0) {
        int t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    int n;
    scanf("%d", &n);
    char *str = (char *)malloc(sizeof(char) * 100000);
    scanf("%s", str);
    int *a = (int *)malloc(sizeof(int) * n);
    char *p = str;
    for (int i = 0; i < n; i++) {
        a[i] = atoi(p);
        p = strchr(p, ' ');
        p++;
    }
    free(str);
    int mod = 1000000007;
    long p = 1;
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }
    long *q = (long *)malloc(sizeof(long) * n);
    q[0] = 1;
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        long val = q[i] + q[n - i - 1] - 1;
        val *= a[i];
        val %= mod;
        val *= p;
        val %= mod;
        ans += val;
        ans %= mod;
    }
    printf("%ld\n", ans);
    free(a);
    free(q);
    return 0;
}

