#include <stdio.h>
#include <math.h>

int main() {
	int n, a[50], p, b = 0, c = 0;

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

	//cout << "b:" << b << " c:" << c << endl;
	long long bsum = 0, csum = 0;
	bsum = (long long)pow(2, b);

	if (p == 0) {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 0) {
				csum += nCr(c, i);
			}
		}
	}
	else {
		for (int i = 0; i <= c; i++) {
			if (i % 2 == 1) {
				csum += nCr(c, i);
			}
		}
	}

	long long ans = bsum*csum;
	printf("%lld\n", ans);
}

