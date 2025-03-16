#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int c[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + (n - i) * c[i]) % 1000000007;
	}
	printf("%d\n", ans * pow(4, n - 1) % 1000000007);
	return 0;
}

