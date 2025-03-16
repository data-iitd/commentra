#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	switch (b-a) {
		case 0:
			printf("delicious\n");
			break;
		case 1:
			printf("safe\n");
			break;
		default:
			printf("dangerous\n");
			break;
	}
	return 0;
}
