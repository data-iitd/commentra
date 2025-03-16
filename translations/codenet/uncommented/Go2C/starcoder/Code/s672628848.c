#include <stdio.h>

int main() {
	int a, b, c, d, e;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	int al[5] = {a, b, c, d, e};

	for (int n = 0; n < 5; n++) {
		if (al[n] == 0) {
			printf("%d\n", n + 1);
			break;
		}
	}
}
