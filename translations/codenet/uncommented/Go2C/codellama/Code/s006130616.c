#include <stdio.h>

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	int a[n][m];
	int p[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 1200001;
	int tot = 0;
	int ok = 0;
	for (int bits = 0; bits < (1 << n); bits++) {
		tot = 0;
		ok = 1;
		int skill[m];
		for (int i = 0; i < n; i++) {
			if (bits >> i) & 1 == 1 {
				tot += p[i];
				for (int j = 0; j < m; j++) {
					skill[j] += a[i][j];
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if skill[i] < x {
				ok = 0;
				break;
			}
		}

		if (ok) {
			if (ans > tot) {
				ans = tot;
			}
		}
	}

	if (ans != 1200001) {
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}

	return 0;
}

