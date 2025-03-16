#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, k;
	int *a;
	int i, sum, ans;

	scanf("%d %d", &n, &k);
	a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	// 変数未使用エラー回避
	a[0] = 0;

	sum = k;
	ans = 1;
	while (sum < n) {
		sum = sum - 1 + k;
		ans++;
	}
	printf("%d\n", ans);
	free(a);
	return 0;
}
