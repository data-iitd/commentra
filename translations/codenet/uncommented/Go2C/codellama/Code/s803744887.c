#include <stdio.h>
#include <stdlib.h>

#define MX 10000

int main() {
	int sieve[MX];
	int primes[MX];
	int i, j;
	for (i = 2; i < MX; i++) {
		if (sieve[i] != 0) {
			continue;
		}
		primes[i] = i;
		for (j = i + i; j < MX; j += i) {
			sieve[j] = i;
		}
	}

	int n;
	scanf("%d", &n);
	int ans = 0;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ans++;
		for (j = 0; j < MX; j++) {
			if (x > primes[j] && x%primes[j] == 0) {
				ans--;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

