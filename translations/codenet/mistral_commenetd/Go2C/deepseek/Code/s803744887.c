#include <stdio.h>

#define MX 10000

int main() {
    int sieve[MX];
    int primes[MX];
    int prime_count = 0;

    for (int i = 2; i < MX; i++) {
        if (sieve[i] != 0) {
            continue;
        }
        primes[prime_count++] = i;
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
        for (int j = 0; j < prime_count; j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--;
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
