
#include <stdio.h>

int main() {
    const int MX = 10000;
    int sieve[MX] = {0};
    int primes[MX] = {0};
    int nprimes = 0;
    for (int i = 2; i < MX; i++) {
        if (sieve[i]!= 0) {
            continue;
        }
        primes[nprimes++] = i;
        for (int j = i + i; j < MX; j += i) {
            sieve[j] = i;
        }
    }

    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans++;
        for (int j = 0; j < nprimes; j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
