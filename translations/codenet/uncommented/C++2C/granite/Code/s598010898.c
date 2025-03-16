
#include <stdio.h>
int main(void) {
	int n, a[100], b[100], sum = 0;scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (a[i] - b[i] > 0) {
			sum += a[i] - b[i];
		}
	}
	printf("%d\n", sum);
}
