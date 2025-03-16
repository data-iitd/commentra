#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);

	int ret = a + b;

	if (ret < (a - b)) {
		ret = a - b;
	}
	if (ret < (a * b)) {
		ret = a * b;
	}

	printf("%d\n", ret);
	return 0;
}
