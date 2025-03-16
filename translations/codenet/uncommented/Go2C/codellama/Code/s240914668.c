#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, l, r;
	int *a;
	int ans;

	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	ans = 0;
	for (i = 0; i < n; i++) {
		l = i;
		r = i + 1;
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}
		ans++;
		i = r;
	}
	printf("%d\n", ans);
	free(a);
	return 0;
}
