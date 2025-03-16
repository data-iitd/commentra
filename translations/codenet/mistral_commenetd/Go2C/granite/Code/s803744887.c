
#include <stdio.h>
#include <stdlib.h>

#define MX 10000

int main() {
    int sieve[MX] = {0};
    int primes[MX] = {0};
    int i, j, n, x, ans;

    for (i = 2; i < MX; i++) {
        if (sieve[i]!= 0) {
            continue;
        }
        primes[i] = 1;
        for (j = i + i; j < MX; j += i) {
            sieve[j] = i;
        }
    }

    scanf("%d", &n);
    ans = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        ans++;
        for (j = 0; j < MX; j++) {
            if (primes[j] == 1 && x > j && x % j == 0) {
                ans--;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
