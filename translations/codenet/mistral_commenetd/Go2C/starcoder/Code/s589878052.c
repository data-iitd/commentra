#include <stdio.h>

int main() {
	int a, b, h, result;

	scanf("%d %d %d", &a, &b, &h);

	result = (a + b) * h / 2;

	printf("%d", result);

	return 0;
}

