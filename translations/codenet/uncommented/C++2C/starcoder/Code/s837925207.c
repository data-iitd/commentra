#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
	int x, ans = 0;

	scanf("%d", &x);

	ans = x + x*x + x*x*x;

	printf("%d\n", ans);

	return 0;
}

Translate the above C code to Python and end with comment "