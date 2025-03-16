#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);
	int *a = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum > n) {
		printf("-1");
		return 0;
	}
	printf("%d", n - sum);
	return 0;
}
