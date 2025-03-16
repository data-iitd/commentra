#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);

	int **a = (int**)malloc(sizeof(int*) * n);
	int *p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		a[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 1200001;
	int tot;
	int ok;
	for (int bits = 0; bits < 1<<n; bits++) {
		tot = 0;
		ok = 1;
		int *skill = (int*)malloc(sizeof(int) * m);
		for (int i = 0; i < n; i++) {
			if ((bits>>i)&1 == 1) {
				tot += p[i];
				for (int j = 0; j < m; j++) {
					skill[j] += a[i][j];
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (skill[i] < x) {
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

	if (ans!= 1200001) {
		printf("%d\n", ans);
	} else {
		printf("-1\n");
	}
}

