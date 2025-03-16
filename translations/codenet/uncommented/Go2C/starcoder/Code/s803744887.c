#include <stdio.h>
#include <stdlib.h>

int main() {
	const int MX = 10000;
	int sieve[MX];
	int *primes = (int *)malloc(MX * sizeof(int));
	for (int i = 0; i < MX; i++) {
		sieve[i] = 0;
	}
	for (int i = 2; i < MX; i++) {
		if (sieve[i]!= 0) {
			continue;
		}
		primes[0] = i;
		int j = i + i;
		while (j < MX) {
			sieve[j] = i;
			j += i;
		}
	}

	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ans++;
		for (int j = 0; j < MX; j++) {
			if (x > primes[j] && x%primes[j] == 0) {
				ans--;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
