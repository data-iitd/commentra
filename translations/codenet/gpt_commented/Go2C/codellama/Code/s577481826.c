#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, ret;
	scanf("%d %d", &a, &b);
	ret = a + b;
	if (ret < (a - b)) {
		ret = a - b;
	}
	if (ret < (a * b)) {
		ret = a * b;
	}
	printf("%d\n", ret);
	return 0;
}
