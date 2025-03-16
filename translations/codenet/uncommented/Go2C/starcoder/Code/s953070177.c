#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int *aa = (int *)malloc(sizeof(int) * (n+2));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &aa[i+1]);
		sum += abs(aa[i+1] - aa[i]);
	}
	sum += abs(aa[n+1] - aa[n]);
	for (int i = 1; i < n+1; i++) {
		int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
		printf("%d\n", ans);
	}
	return 0;
}
