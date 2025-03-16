#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define fd(i,b,a) for(i=b;i>=a;i--)
#define nl '\n'

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int i, j, k, n, m, t, a, b, c, d, x, y, z, u, v, w, p, q, r, s, e, f, g, h, len, ans, pos, tmp, count;
    int mod = 998244353;
    int __N = 8000;
    int g1[__N + 1];
    int g2[__N + 1];
    int inverse[__N + 1];
    g1[0] = 1;
    g1[1] = 1;
    g2[0] = 1;
    g2[1] = 1;
    inverse[0] = 0;
    inverse[1] = 1;
    for (i = 2; i <= __N; i++) {
        g1[i] = (g1[i - 1] * i) % mod;
        inverse[i] = (inverse[mod % i] * (mod / i)) % mod;
        g2[i] = (g2[i - 1] * inverse[i - 1]) % mod;
    }
    int cmb(int n, int r, int mod) {
        if (r < 0 || r > n)
            return 0;
        r = min(r, n - r);
        return g1[n] * g2[r] * g2[n - r] % mod;
    }
    int kumiawase(int p, int q) {
        return cmb(p + q - 1, q - 1, mod);
    }
    int solve(int n) {
        assert(n <= K + 1);
        int ans = 0;
        int kumi = (n - 1) / 2;
        for (p = kumi + 1; p <= N; p++) {
            ans += 2 * p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - (n % 2 == 0)));
            if (n % 2 == 0 && N - p - 1 >= 0)
                ans += 2 * p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - (n % 2 == 0)));
        }
        return ans;
    }
    int ans[2 * K + 1];
    for (i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) {
            tmp = solve(i) % 998244353;
            ans[i - 2] = tmp;
            printf("%d\n", tmp);
        } else {
            printf("%d\n", ans[2 * K + 1 - i]);
        }
    }
    return 0;
}

