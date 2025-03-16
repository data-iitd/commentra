#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i, r = i + 1;
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}
		ans++;
		i = r;
	}
	printf("%d", ans);
	return 0;
}

