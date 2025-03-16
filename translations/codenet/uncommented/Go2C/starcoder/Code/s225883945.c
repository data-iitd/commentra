#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int *a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	// 変数未使用エラー回避
	a[0] = 0;

	int sum = k;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		sum = sum - 1 + k;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
