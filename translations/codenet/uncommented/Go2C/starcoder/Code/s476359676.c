#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int aPrev = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a > i || a > aPrev + 1) {
			printf("-1\n");
			return 0;
		}
		if (a == aPrev + 1) {
			ans++;
		} else {
			ans += a;
		}
		aPrev = a;
	}
	printf("%d\n", ans);
	return 0;
}
