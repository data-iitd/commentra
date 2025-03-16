#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int h, n, a;
	scanf("%d %d", &h, &n);
	a = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a += x;
	}
	if (h > a) {
		printf("No");
	} else {
		printf("Yes");
	}
	return 0;
}
