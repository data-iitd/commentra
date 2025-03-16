
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll combi(int n, int k) {
    ll min = (ll)k * (k - 1) / 2;
    ll max = (ll)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll total = 0;
    for (int i = k; i <= n + 1; i++) {
        ll comb = combi(n, i);
        total += comb;
        total %= (1000000007);
    }

    printf("%lld\n", total);

    return 0;
}
