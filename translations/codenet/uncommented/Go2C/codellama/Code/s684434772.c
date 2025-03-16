
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, k;
	int64_t total;
	int i;

	scanf("%d %d", &n, &k);

	total = 0;
	for (i = k; i <= n + 1; i++) {
		total += combi(n, i);
		total = total % (pow(10, 9) + 7);
	}
	printf("%lld\n", total);

	return 0;
}

int64_t combi(int n, int k) {
	int64_t min = (k - 1) * k / 2;
	int64_t max = (2 * n - k + 1) * k / 2;
	return max - min + 1;
}

int pow(int base, int exponent) {
	int answer = 1;
	for (int i = 0; i < exponent; i++) {
		answer *= base;
	}
	return answer;
}

