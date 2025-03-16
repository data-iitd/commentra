#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

long long nchoosek[4001][4001];

void initialize_nchoosek() {
    for (int i = 0; i < 4001; i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1;
    }
    for (int i = 2; i < 4001; i++) {
        for (int j = 1; j < i; j++) {
            nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    initialize_nchoosek();
    int k, n;
    scanf("%d %d", &k, &n);

    for (int i = 2; i <= 2 * k; i++) {
        int pairs;
        if (i > k) {
            pairs = k - i / 2;
        } else {
            pairs = (i - 1) / 2;
        }
        int active = k - 2 * pairs;
        if (i % 2 == 0) active -= 1;

        long long times2 = 1;
        long long total = 0;

        for (int j = 0; j <= pairs; j++) {
            long long choice = times2 * nchoosek[pairs][j] % MOD;
            times2 = times2 * 2 % MOD;
            if (active + j - 1 < 0) continue;
            total += choice * nchoosek[n + active - 1][active + j - 1];
            if (i % 2 == 0) {
                total += choice * nchoosek[n + active - 2][active + j - 1];
            }
            total %= MOD;
        }
        printf("%lld\n", total);
    }
    return 0;
}
