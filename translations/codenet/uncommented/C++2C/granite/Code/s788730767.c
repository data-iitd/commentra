
#include <stdio.h>
#include <math.h>

int main() {
	int n, p, a[50], b = 0, c = 0;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			b++;
		}
		else {
			c++;
		}
	}

	long long bsum = 1, csum = 0;
	for (int i = 0; i < b; i++) {
		bsum *= 2;
	}

	if (p == 0) {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 0) {
				csum += 1;
			}
		}
	}
	else {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 1) {
				csum += 1;
			}
		}
	}

	long long ans = bsum*csum;
	printf("%lld\n", ans);
}
