
#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (C - A + B < 0) {
		printf("0\n");
	} else {
		printf("%d\n", C - A + B);
	}
	return 0;
}
