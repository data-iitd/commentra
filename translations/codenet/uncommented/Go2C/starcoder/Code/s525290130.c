#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, q, b, e;
	scanf("%d", &n);
	int *a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &b, &e);
		for (int j = b; j < e; j++) {
			int t = a[j];
			a[j] = a[e-1-j];
			a[e-1-j] = t;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
