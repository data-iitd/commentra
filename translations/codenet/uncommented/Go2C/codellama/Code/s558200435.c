#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int *a = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int *b = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		int x = 0;
		while (x < n && b[x] < a[i]) {
			x++;
		}
		if (x == n) {
			b[n] = a[i];
		} else {
			b[x] = a[i];
		}
	}

	printf("%d\n", n);

	free(a);
	free(b);

	return 0;
}

