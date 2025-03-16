#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;
	int aPrev = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		switch (a) {
		case a > i || a > aPrev + 1:
			printf("-1\n");
			return 0;
		case a == aPrev + 1:
			ans++;
		default:
			ans += a;
		}
		aPrev = a;
	}
	printf("%d\n", ans);
	return 0;
}
