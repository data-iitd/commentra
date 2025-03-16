#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	switch (1) {
		case (b-a <= 0):
			printf("delicious");
			break;
		case (b-a <= x):
			printf("safe");
			break;
		default:
			printf("dangerous");
			break;
	}
	return 0;
}
