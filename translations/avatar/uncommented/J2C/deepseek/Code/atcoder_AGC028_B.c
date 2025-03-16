#include <stdio.h>
#include <stdlib.h>

long long modinv(long long a, int m) {
    long long b = m;
    long long u = 1;
    long long v = 0;
    long long tmp;
    while (b > 0) {
        long long t = a / b;
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
    int a[n];
    char sa[n * 5]; // Assuming each number can be up to 5 digits long
    fgets(sa, sizeof(sa), stdin); // Read the newline character
    fgets(sa, sizeof(sa), stdin);
    char *token = strtok(sa, " ");
    for (int i = 0; i < n; i++) {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    int mod = 1000000007;
    long long p = 1;
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }

    long long q[n];
    q[0] = 1;
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long val = q[i] + q[n - i - 1] - 1;
        val *= a[i];
        val %= mod;
        val *= p;
        val %= mod;
        ans += val;
        ans %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}
