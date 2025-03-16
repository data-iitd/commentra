#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int k, x;
	scanf("%d %d", &k, &x);
	if (k*500 >= x) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
