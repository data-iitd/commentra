#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 998244353

int main() {
    int K, N;
    scanf("%d %d", &K, &N);
    int g1[8000] = {1, 1};
    int g2[8000] = {1, 1};
    int inverse[8000] = {0, 1};
    for (int i = 2; i <= 8000; i++) {
        g1[i] = (g1[i - 1] * i) % MOD;
        inverse[i] = (-inverse[MOD % i] * (MOD / i)) % MOD;
        g2[i] = (g2[i - 1] * inverse[i]) % MOD;
    }
    int ans[200000];
    for (int i = 2; i <= 2 * K + 1; i++) {
        int kumi = (i - 1) / 2;
        int tmp = 0;
        for (int p = 0; p <= kumi; p++) {
            if (p > N) break;
            tmp += pow(2, p) * cmb(kumi, p, MOD) * kumiawase(N - p, p + (K - kumi * 2 - (i % 2 == 0)));
            if (i % 2 == 0 && N - p - 1 >= 0) tmp += pow(2, p) * cmb(kumi, p, MOD) * kumiawase(N - p - 1, p + (K - kumi * 2 - (i % 2 == 0)));
        }
        ans[i - 2] = tmp % MOD;
    }
    for (int i = 2; i <= 2 * K + 1; i++) {
        if (i <= K + 1) printf("%d\n", ans[i - K]);
        else printf("%d\n", ans[2 * K - i + K]);
    }
    return 0;
}

