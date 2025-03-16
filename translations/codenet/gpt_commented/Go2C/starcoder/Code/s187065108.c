

#include <stdio.h>
#include <stdlib.h>

int main() {
	int r, D, x;
	scanf("%d %d %d", &r, &D, &x);
	for (int i = 1; i <= 10; i++) {
		x = r*x - D;
		printf("%d\n", x);
	}
	return 0;
}

