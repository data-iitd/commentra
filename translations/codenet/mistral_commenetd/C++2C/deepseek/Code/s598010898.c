#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int a[100];
	int b[100];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);

		if (a[i] - b[i] > 0) {
			sum += a[i] - b[i];
		}
	}

	printf("%d\n", sum);
}

