
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i*i < n; i++) {
		if (n%i == 0) {
			if (n%(n/i-1) == i) {
				ans += n/i-1;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

