#include <stdio.h>

int main() {
	int K, X;
	scanf("%d %d", &K, &X);
	if (500*K >= X) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
