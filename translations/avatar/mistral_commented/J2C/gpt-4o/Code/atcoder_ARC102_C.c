#include <stdio.h>

#define MOD 998244353
#define MAX 4001

long nchoosek[MAX][MAX];

void initialize_nchoosek() {
    for (int i = 0; i < MAX; i++) {
        nchoosek[i][0] = nchoosek[i][i] = 1;
    }

    for (int i = 2; i < MAX; i++) {
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

        long times2 = 1;
        long total = 0;

        for (int j = 0; j <= pairs; j++) {
            long choice = times2 * nchoosek[pairs][j] % MOD;
            times2 = times2 * 2 % MOD;

            if (active + j - 1 < 0) continue;

            total += choice * nchoosek[n + active - 1][active + j - 1] % MOD;

            if (i % 2 == 0) {
                total += choice * nchoosek[n + active - 2][active + j - 1] % MOD;
            }

            total %= MOD;
        }

        printf("%ld\n", total);
    }

    return 0;
}

// <END-OF-CODE>
