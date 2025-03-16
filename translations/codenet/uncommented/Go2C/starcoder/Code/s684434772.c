#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int combi(int n, int k) {
	int min = (k-1) * k / 2;
	int max = (2*n-k+1) * k / 2;
	return max - min + 1;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int total = 0;
	for (int i = k; i <= n+1; i++) {
		total += combi(n, i);
		total = total % (1000000007);
	}
	printf("%d\n", total);
}

