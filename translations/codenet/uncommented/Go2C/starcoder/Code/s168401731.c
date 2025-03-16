#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a % 2 == 1) {
			printf("first\n");
			break;
		}
	}
	printf("second\n");
	return 0;
}
